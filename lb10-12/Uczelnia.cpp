//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Uczelnia.cpp
//  @ Date : 24.05.2023
//  @ Author :
//
//

#include <stdexcept>
#include "Uczelnia.h"
#include "Kurs.h"
#include "Uzytkownik.h"
#include "Wiadomosc.h"
#include "Wykladowca.h"
#include "Student.h"

Uczelnia::Uczelnia(string nazwa) {
    this->nazwa = nazwa;
}

Uzytkownik* Uczelnia::zaloguj(string login, string haslo) {
    try {
        Uzytkownik* u = this->uzytkownicy.at(login);
        if (u->getHaslo() == haslo) {
            return u;
        }
        return nullptr;
    } catch (std::out_of_range const& _) {
        return nullptr;
    }
}

bool Uczelnia::zarejestruj(string login, string haslo, string nazwisko) {
    if (this->uzytkownicy.find(login) != this->uzytkownicy.end()) {
        // Uzytkownik juz istnieje!
        return false;
    }

    this->uzytkownicy[login] = new Student(login, haslo, nazwisko);
    return true;
}

bool Uczelnia::zarejestrujWykladowce(string login, string haslo, string nazwisko) {
    // TODO: Sprawdzanie czy mamy uprawnienia do tworzenia konta wykladowcy? :)
    if (this->uzytkownicy.find(login) != this->uzytkownicy.end()) {
        // Uzytkownik juz istnieje!
        return false;
    }

    this->uzytkownicy[login] = new Wykladowca(login, haslo, nazwisko);
    return true;
}

bool Uczelnia::wyslijWiadomosc(Uzytkownik* nadawca, string odbiorca, string temat, string tresc) {
    auto odb = this->getUzytkownik(odbiorca);

    // Jezeli odbiorca nie istnieje
    if (odb == nullptr) {
        return false;
    }

    this->wiadomosci.push_back(new Wiadomosc(nadawca, odb, temat, tresc));
    return true;
}

void Uczelnia::wyswietlStudentow() {
    printf("Studenci uczelni '%s':\n", this->getNazwa().c_str());

    for (const std::pair<const std::string, Uzytkownik*>& v : this->uzytkownicy) {
        Student* s = dynamic_cast<Student*>(v.second);
        if (s != nullptr) {
            printf("\t[%s] %s\n", s->getLogin().c_str(), s->getNazwisko().c_str());
        }
    }
}

void Uczelnia::wyswietlWykladowcow() {
    printf("Wykladowcy uczelni '%s':\n", this->getNazwa().c_str());

    for (const std::pair<const std::string, Uzytkownik*>& v : this->uzytkownicy) {
        Wykladowca* w = dynamic_cast<Wykladowca*>(v.second);
        if (w != nullptr) {
            printf("\t[%s] %s\n", w->getLogin().c_str(), w->getNazwisko().c_str());
        }
    }
}

void Uczelnia::wyswietlKursy() {
    printf("Dostepne kursy: \n");

    for (Kurs* k : this->kursy) {
        printf("\t[%d] %s\n", k->getId(), k->getNazwa().c_str());
    }
}

void Uczelnia::wyswietlKursy(Uzytkownik* uzytkownik) {
    printf("Kursy uzytkownika '%s': \n", uzytkownik->getNazwisko().c_str());

    for (Kurs* k : this->getKursy(uzytkownik)) {
        printf("\t[%d] %s\n", k->getId(), k->getNazwa().c_str());
    }
}

void Uczelnia::wyswietlOceny(Student* student) {
    printf("Oceny studenta '%s': \n", student->getNazwisko().c_str());

    for (Kurs* k : this->kursy) {
        // Jezeli uzytkownik jest studentem i nalezy do kursu
        if (k->czyNalezy(student)) {
            float ocena = k->getOcena(student);
            if (ocena == 0.0f) {
                printf("\t%s: Brak oceny\n", k->getNazwa().c_str());
            } else {
                printf("\t%s: %.1f\n", k->getNazwa().c_str(), ocena);
            }
        }
    }
}

void Uczelnia::wyswietlWiadomosci(Uzytkownik* uzytkownik) {
    printf("Wiadomosci uzytkownika '%s': \n", uzytkownik->getNazwisko().c_str());

    for (Wiadomosc* w : this->getWiadomosci(uzytkownik)) {
        printf("\t Od %s: %s\n\t\t%s\n\n", w->getNadawca().getNazwisko().c_str(), w->getTemat().c_str(), w->getTresc().c_str());
    }
}

Kurs* Uczelnia::utworzKurs(string nazwa, Wykladowca* prowadzacy) {
    int id = this->kursy.size();

    auto kurs = new Kurs(id, nazwa, prowadzacy);
    this->kursy.push_back(kurs);
    return kurs;
}

Kurs* Uczelnia::getKurs(int id) {
    try {
        return this->kursy.at(id);
    } catch (std::out_of_range const& _) {
        return nullptr;
    }
}

vector<Kurs*> Uczelnia::getKursy() {
    return this->kursy;
}

vector<Kurs*> Uczelnia::getKursy(Uzytkownik *uzytkownik) {
    vector<Kurs*> kursy;

    for (Kurs* kurs : this->kursy) {
        Student* s = dynamic_cast<Student*>(uzytkownik);

        // Jezeli uzytkownik jest studentem i nalezy do kursu, lub uzytkownik jest prowadzacym kursu
        if ((s != nullptr && kurs->czyNalezy(s)) || kurs->getProwadzacy().getLogin() == uzytkownik->getLogin()) {
            kursy.push_back(kurs);
        }
    }

    return kursy;
}

Uzytkownik *Uczelnia::getUzytkownik(string login) {
    try {
        return this->uzytkownicy.at(login);
    } catch (std::out_of_range const& _) {
        return nullptr;
    }
}

string Uczelnia::getNazwa() {
    return this->nazwa;
}

vector<Wiadomosc *> Uczelnia::getWiadomosci(Uzytkownik *uzytkownik) {
    vector<Wiadomosc*> wiadomosci;

    for (Wiadomosc* w : this->wiadomosci) {
        if (w->getOdbiorca().getLogin() == uzytkownik->getLogin()) {
            wiadomosci.push_back(w);
        }
    }

    return wiadomosci;
}
