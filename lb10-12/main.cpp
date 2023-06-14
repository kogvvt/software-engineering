#include <iostream>
#include <functional>
#include <string>
#include <random>
#include <map>
#include "Kurs.h"
#include "Uczelnia.h"
#include "Uzytkownik.h"
#include "Wykladowca.h"
#include "Student.h"

void wyswietlKursyZDolaczeniem(Uczelnia* uczelnia, Student* student);
void wyslijWiadomosc(Uczelnia* uczelnia, Uzytkownik* uzytkownik);

void zarzadzajKursami(Uczelnia* uczelnia, Wykladowca* wykladowca);
void utworzKurs(Uczelnia* uczelnia, Wykladowca* wykladowca);

struct Komenda {
    std::string nazwa;
    std::function<int(Uczelnia*, Uzytkownik*)> f;
};

std::map<char, Komenda> komendy_student = {
    { 'x', { "Wyloguj sie", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { return -1; } } },
    { '1', { "Wyswietl kursy", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { wyswietlKursyZDolaczeniem(uczelnia, dynamic_cast<Student*>(uzytkownik)); return 0; } } },
    { '2', { "Wyswietl Twoje kursy", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { uczelnia->wyswietlKursy(uzytkownik); return 0; } } },
    { '3', { "Wyswietl Twoje oceny", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { uczelnia->wyswietlOceny(dynamic_cast<Student*>(uzytkownik)); return 0; } } },
    { '4', { "Wyswietl Twoje wiadomosci", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { uczelnia->wyswietlWiadomosci(uzytkownik); return 0; } } },
    { '5', { "Wyswietl wykladowcow", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { uczelnia->wyswietlWykladowcow(); return 0; } } },
    { '6', { "Wyslij wiadomosc", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { wyslijWiadomosc(uczelnia, uzytkownik); return 0; } } }
};

std::map<char, Komenda> komendy_wykladowca = {
    { 'x', { "Wyloguj sie", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { return -1; } } },
    { '1', { "Wyswietl Twoje kursy", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { uczelnia->wyswietlKursy(uzytkownik); return 0; } } },
    { '2', { "Wyswietl Twoje wiadomosci", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { uczelnia->wyswietlWiadomosci(uzytkownik); return 0; } } },
    { '3', { "Wyswietl wykladowcow", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { uczelnia->wyswietlWykladowcow(); return 0; } } },
    { '4', { "Zarzadzaj kursami", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { zarzadzajKursami(uczelnia, dynamic_cast<Wykladowca*>(uzytkownik)); return 0; } } },
    { '5', { "Utworz kurs", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { utworzKurs(uczelnia, dynamic_cast<Wykladowca*>(uzytkownik)); return 0; } } },
    { '6', { "Wyslij wiadomosc", [] (Uczelnia* uczelnia, Uzytkownik* uzytkownik) { wyslijWiadomosc(uczelnia, uzytkownik); return 0; } } }
};

// Za crossplatformosc naleza sie dodatkowe punkty
void clear_screen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// Wysylanie wiadomosci (wspolne dla wykladowcy i studenta)
void wyslijWiadomosc(Uczelnia* uczelnia, Uzytkownik* uzytkownik) {
    std::cout << "Podaj login adresata: ";
    std::string adresat;
    std::cin >> adresat;

    std::string temat;
    std::string wiadomosc;

    std::cout << "Podaj temat: ";
    std::getline(std::cin >> std::ws, temat);

    std::cout << "Podaj wiadomosc: ";
    std::getline(std::cin >> std::ws, wiadomosc);

    bool result = uczelnia->wyslijWiadomosc(uzytkownik, adresat, temat, wiadomosc);

    if (result) {
        std::cout << "Wiadomosc zostala wyslana!\n";
    } else {
        std::cout << "Nie udalo sie wyslac wiadomosc, czy adresat istnieje?\n";
    }
}

// Wyswietlanie wszystkich kursow i pytanie o dolaczenie (dla studenta)
void wyswietlKursyZDolaczeniem(Uczelnia* uczelnia, Student* student) {
    uczelnia->wyswietlKursy();

    std::cout << "Czy chcesz dolaczyc do kursu? [t/N]: ";
    char answer;
    std::cin >> answer;

    if (answer == 'T' || answer == 't') {
        std::cout << "Podaj id kursu do ktorego chcesz dolaczyc: ";
        int id;
        std::cin >> id;

        auto kurs = uczelnia->getKurs(id);
        if (kurs == nullptr) {
            std::cout << "Kurs nie istnieje!\n";
            return;
        }

        if (kurs->dolacz(student)) {
            std::cout << "Dolaczono do kursu '" << kurs->getNazwa() << "'!\n";
        } else {
            std::cout << "Nie udalo sie dolaczyc do kursu\n";
        }
    }
}

void wystawOcene(Uczelnia* uczelnia, Wykladowca* wykladowca, Kurs* kurs) {
    std::string ch;
    do {
        clear_screen();
        std::cout << "Wystawianie ocen w kursie '" << kurs->getNazwa() << "'\n";
        std::cout << "----------------------\n";
        for (auto &student : kurs->getUczestnicy()) {
            std::cout << "[" << student->getLogin() << "] " << student->getNazwisko() << "\n";
        }
        std::cout << "x. Wyjdz\n\n";
        std::cout << "Wybierz studenta: ";
        std::cin >> ch;

        // Znajdz studenta
        for (auto &student : kurs->getUczestnicy()) {
            if (student->getLogin() == ch) {
                float ocena = -1.f;
                do {
                    clear_screen();
                    std::cout << "Wystawianie oceny dla '" << student->getNazwisko() << "' w '" << kurs->getNazwa() << "'\n";
                    std::cout << "Podaj ocene <0.0 - 5.0>: ";
                    std::cin >> ch;
                    ocena = std::stof(ch);
                } while (ocena < 0.f || ocena > 5.f);

                kurs->setOcena(student, ocena);
                std::cout << "Wystawiono ocene " << ocena << " studentowi '" << student->getNazwisko() << "' w '" << kurs->getNazwa() << "'\n";
                return;
            }
        }
    } while (ch != "x");
}

void zarzadzajKursem(Uczelnia* uczelnia, Wykladowca* wykladowca, Kurs* kurs) {
    char ch;
    while (true) {
        clear_screen();
        std::cout << "Zarzadzanie kursem '" << kurs->getNazwa() << "'\n";
        std::cout << "----------------------\n";
        std::cout << "1. Zmien nazwe\n";
        std::cout << "2. Wyswietl studentow\n";
        std::cout << "3. Wystaw ocene\n";
        std::cout << "x. Wyjdz\n\n";

        std::cout << "Wybierz opcje: ";
        std::cin >> ch;

        switch (ch) {
            case '1': {
                std::cout << "Podaj nowa nazwe kursu: ";
                std::string nazwa;
                std::getline(std::cin >> std::ws, nazwa);

                std::string staraNazwa = kurs->getNazwa();
                kurs->setNazwa(nazwa);

                std::cout << "Zmieniono nazwe kursu z '" << staraNazwa << "' na '" << kurs->getNazwa() << "'!\n";
                break;
            }
            case '2': {
                clear_screen();
                std::cout << "Lista studentow kursu '" << kurs->getNazwa() << "'\n";
                for (auto &student : kurs->getUczestnicy()) {
                    char ocena[20];
                    if (kurs->getOcena(student) == 0.0f) {
                        sprintf(ocena, "Brak oceny");
                    } else {
                        sprintf(ocena, "%.1f", kurs->getOcena(student));
                    }
                    std::cout << "[" << student->getLogin() << "] " << student->getNazwisko() << " (ocena " << ocena << ")\n";
                }
                break;
            }
            case '3':
                wystawOcene(uczelnia, wykladowca, kurs);
                break;
            case 'x':
                return;
        }
        std::cout << "[ENTER]\n";
        std::cin.get(); std::cin.get();
    };
}

// Wyswietlanie wlasnych kursow, pytanie o wybor kursu i co chcemy z nim zrobic? (dla wykladowcy)
void zarzadzajKursami(Uczelnia* uczelnia, Wykladowca* wykladowca) {
    // Wybieranie kursu
    std::string ch;
    while (true) {
        clear_screen();
        std::cout << "Zarzadzanie kursami\n";
        std::cout << "----------------------\n";
        for (auto &kurs : uczelnia->getKursy(wykladowca)) {
            std::cout << kurs->getId() << ". " << kurs->getNazwa() << "\n";
        }
        std::cout << "x. Wroc\n\n";
        std::cout << "Wybierz kurs: ";
        std::cin >> ch;

        if (ch == "x") {
            return;
        } else {
            auto kurs = uczelnia->getKurs(std::stoi(ch));

            if (kurs != nullptr) {
                zarzadzajKursem(uczelnia, wykladowca, kurs);
                return;
            }
        }
    };
}

// Tworzenie kursu (dla wykladowcy)
void utworzKurs(Uczelnia* uczelnia, Wykladowca* wykladowca) {
    std::cout << "Podaj nazwe kursu: ";
    std::string nazwa;

    std::getline(std::cin >> std::ws, nazwa);

    auto kurs = uczelnia->utworzKurs(nazwa, wykladowca);

    if (kurs != nullptr) {
        std::cout << "Utworzono kurs '" << kurs->getNazwa() << "' o id " << kurs->getId() << std::endl;
    } else {
        std::cout << "Nie udalo sie utworzyc kursu!" << std::endl;
    }
}

Uzytkownik* zaloguj(Uczelnia* uczelnia) {
    std::cout << "Przykladowi uzytkownicy:\n\tWykladowca: login 'jkowalski', haslo 'haslo'\n\tStudent: login '1234', haslo 'haslo'\n\n";

    std::string login;
    std::string haslo;
    Uzytkownik* student = nullptr;

    do {
        std::cout << "Podaj login: ";
        std::cin >> login;
        std::cout << "Podaj haslo: ";
        std::cin >> haslo;

        student = uczelnia->zaloguj(login, haslo);
        if (student == nullptr) {
            std::cout << "Nieprawidlowe dane!\n\n";
        }
    } while (student == nullptr);

    std::cout << "Zalogowano pomyslnie!\n\n";
    return student;
}

void zarejestruj(Uczelnia* uczelnia) {
    std::string haslo;
    std::string nazwisko;
    bool result = false;
    int numer_indeksu;

    do {
        std::cout << "Podaj imie i nazwisko: ";
        std::getline(std::cin >> std::ws, nazwisko);
        std::cout << "Podaj haslo: ";
        std::cin >> haslo;

        // Wygeneruj numer indeksu
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(100000, 999999);

        do {
            numer_indeksu = dist(rng);
        } while (uczelnia->getUzytkownik(std::to_string(numer_indeksu)) != nullptr);

        result = uczelnia->zarejestruj(std::to_string(numer_indeksu), haslo, nazwisko);

        if (!result) {
            std::cout << "Nie udalo sie stworzyc uzytkownika!\n";
        }
    } while (result == false);

    std::cout << "\nKonto utworzone pomyslnie, twoj numer indeksu (ktory jest loginem) to '" << numer_indeksu << "'!\n\n";
}

// Wyswietla glowne menu po zalogowaniu z dostepnymi opcjami w zaleznosci od "rangi"
void show_menu(Uczelnia* uczelnia, Uzytkownik* uzytkownik, bool student) {
    map<char, Komenda> *komendy = student ? &komendy_student : &komendy_wykladowca;

    char ch;
    int result = 0;
    do {
        clear_screen(); // W sumie mozna usunac (szczegolnie do screenow) ale ladnie wyglada

        std::cout << "System Obslugi Uczelni (zalogowano jako " << (student ? "student" : "wykladowca") << " " << uzytkownik->getNazwisko() << ")\n";
        std::cout << "----------------------\n";
        for (auto &v : *komendy) {
            std::cout << v.first << ". " << v.second.nazwa << "\n";
        }
        std::cout << "\nWybierz opcje: ";
        std::cin >> ch;

        if (komendy->find(ch) != komendy->end()) { // Jezeli wybrana komenda istnieje, wywolujemy ja
            result = komendy->at(ch).f(uczelnia, uzytkownik);
        }

        if (result != -1) { // Nie czekajmy na enter przy wylogowywaniu (dalej bedziemy czekac w show_interface)
            std::cout << "[ENTER]\n";
            std::cin.get(); std::cin.get();
        }
    } while (result == 0); // Jesli z funkcji dostaniemy inny result code to konczymy menu. Uzywane do wylogowywania
}

void show_interface(Uczelnia* uczelnia) {
    // Menu logowania/rejestracji
    char ch;
    while (true) {
        clear_screen();
        std::cout << "System Obslugi Uczelni\n";
        std::cout << "----------------------\n";
        std::cout << "1. Zaloguj sie\n";
        std::cout << "2. Zarejestruj sie\n";
        std::cout << "x. Wyjdz\n\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> ch;

        switch (ch) {
            case '1': {
                auto uzytkownik = zaloguj(uczelnia);
                bool isStudent = (dynamic_cast<Student*>(uzytkownik) != nullptr); // :)))
                show_menu(uczelnia, uzytkownik, isStudent);
                break;
            }
            case '2':
                zarejestruj(uczelnia);
                break;
            case 'x':
                exit(0);
        }

        std::cout << "[ENTER]\n";
        std::cin.get(); std::cin.get();
    };
}

int main() {
    auto uczelnia = new Uczelnia("Uniwersytet Chlopskiego Rozumu");
    std::cout << "Utworzono uczelnie '" << uczelnia->getNazwa() << "'\n";

    // Dodajemy testowych uzytkownikow i kurs
    uczelnia->zarejestrujWykladowce("jkowalski", "haslo", "prof. dr hab. n. med. Jan Kowalski");
    uczelnia->zarejestruj("1234", "haslo", "Piotr Nowak");
    auto w = dynamic_cast<Wykladowca*>(uczelnia->getUzytkownik("jkowalski"));
    auto s = dynamic_cast<Student*>(uczelnia->getUzytkownik("1234"));
    uczelnia->utworzKurs("Filozofia", w);
    uczelnia->utworzKurs("Ekonomia", w);

    // Wysylamy wiadomosc powitalna
    uczelnia->wyslijWiadomosc(s, s->getLogin(), "Witamy!", "Witamy w systemie!");

    // Dopisujemy studenta na ekonomie i wystawiamy ocene
    uczelnia->getKurs(1)->dolacz(s);
    uczelnia->getKurs(1)->setOcena(s, 3.0f);

    // Glowna petla programu z interfejsem
    show_interface(uczelnia);

    return 0;
}
