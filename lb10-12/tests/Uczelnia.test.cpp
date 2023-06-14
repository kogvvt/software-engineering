#include "Uczelnia.test.h"

#include <iostream>

#include "../Student.h"
#include "../Wykladowca.h"
#include "../Kurs.h"
#include "../Uczelnia.h"

void uczelnia_run_tests() {
    std::cout << "Tests: Uczelnia" << std::endl;

    Uczelnia* uczelnia = new Uczelnia("Uczelnia");

    assertm("uczelnia->getNazwa() zwraca nazwe", uczelnia->getNazwa() == "Uczelnia");

    assertm("uczelnia->zarejestruj() zwraca true dla poprawnych danych", uczelnia->zarejestruj("student1", "haslo", "Imie Nazwisko"));
    assertm("uczelnia->zarejestruj() zwraca false dla niepoprawnych danych", !uczelnia->zarejestruj("student1", "haslo", "Imie Nazwisko"));
    assertm("uczelnia->zarejestrujWykladowce() zwraca true dla poprawnych danych", uczelnia->zarejestrujWykladowce("wykladowca1", "haslo", "Imie Nazwisko"));
    assertm("uczelnia->zarejestrujWykladowce() zwraca false dla niepoprawnych danych", !uczelnia->zarejestrujWykladowce("wykladowca1", "haslo", "Imie Nazwisko"));

    assertm("uczelnia->getUzytkownik() zwraca uzytkownika", uczelnia->getUzytkownik("wykladowca1")->getLogin() == "wykladowca1");
    assertm("uczelnia->getUzytkownik() zwraca nullptr", uczelnia->getUzytkownik("nieistniejacy") == nullptr);

    assertm("uczelnia->zaloguj() zwraca nullptr dla zlych danych", uczelnia->zaloguj("wykladowca1", "zlehaslo") == nullptr);
    auto wykladowca = dynamic_cast<Wykladowca*>(uczelnia->zaloguj("wykladowca1", "haslo"));
    assertm("uczelnia->zaloguj() zwraca uzytkownika dla poprawnych danych", wykladowca->getLogin() == "wykladowca1");

    auto student = dynamic_cast<Student*>(uczelnia->zaloguj("student1", "haslo"));

    assertm("uczelnia->getWiadomosci(uzytkownik) ma 0 wiadomosci", uczelnia->getWiadomosci(student).size() == 0);
    assertm("uczelnia->wyslijWiadomosc() zwraca false dla nieistniejacego uzytkownika", !uczelnia->wyslijWiadomosc(wykladowca, "nieistniejacy", "Temat", "Tresc"));
    assertm("uczelnia->wyslijWiadomosc() zwraca true dla istniejacego uzytkownika", uczelnia->wyslijWiadomosc(wykladowca, "student1", "Temat", "Tresc"));
    assertm("uczelnia->getWiadomosci(uzytkownik) ma 1 wiadomosc", uczelnia->getWiadomosci(student).size() == 1);

    assertm("uczelnia->getKursy() ma 0 kursow", uczelnia->getKursy().size() == 0);

    auto kurs0 = uczelnia->utworzKurs("Testowy Kurs", wykladowca);
    auto kurs1 = uczelnia->utworzKurs("Testowy Kurs 2", wykladowca);

    assertm("uczelnia->getKursy() ma 2 kursy", uczelnia->getKursy().size() == 2);

    assertm("uczelnia->getKursy(student) ma 0 kursow", uczelnia->getKursy(student).size() == 0);
    uczelnia->getKurs(0)->dolacz(student);
    assertm("uczelnia->getKursy(student) ma 1 kurs", uczelnia->getKursy(student).size() == 1);

    assertm("uczelnia->utworzKurs() zwraca utworzony kurs", kurs0->getNazwa() == "Testowy Kurs" && kurs0->getProwadzacy().getLogin() == wykladowca->getLogin());
    assertm("Pierwszy utworzony kurs ma id 0", kurs0->getId() == 0);
    assertm("Drugi utworzony kurs ma id 1", kurs1->getId() == 1);

    assertm("uczelnia->getKurs() zwraca kurs", uczelnia->getKurs(1)->getNazwa() == kurs1->getNazwa());

    std::cout << "Uczelnia ALL OK!" << std::endl << std::endl;
}
