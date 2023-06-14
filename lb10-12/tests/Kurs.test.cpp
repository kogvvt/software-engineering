#include "Kurs.test.h"

#include <iostream>

#include "../Student.h"
#include "../Wykladowca.h"
#include "../Kurs.h"

void kurs_run_tests() {
    std::cout << "Tests: Kurs" << std::endl;

    Student* s1 = new Student("student1", "haslo1", "Imie Nazwisko");
    Wykladowca* w1 = new Wykladowca("wykladowca1", "haslo1", "Imie Nazwisko");

    Kurs* kurs = new Kurs(0, "Kurs Testowy", w1);

    assertm("kurs->getId() zwraca id", kurs->getId() == 0);
    assertm("kurs->getNazwa() zwraca nazwe", kurs->getNazwa() == "Kurs Testowy");
    assertm("kurs->getProwadzacy() zwraca prowadzacego", kurs->getProwadzacy().getLogin() == w1->getLogin());
    kurs->setNazwa("Zmieniona Nazwa");
    assertm("kurs->getNazwa() zwraca zmieniona nazwe", kurs->getNazwa() == "Zmieniona Nazwa");

    assertm("kurs->getOcena() dla nie dolaczonego studenta zwraca -1.f", kurs->getOcena(s1) == -1.f);
    assertm("kurs->setOcena() dla nie dolaczonego studenta zwraca false", !kurs->setOcena(s1, 5.f));

    assertm("kurs->getUczestnicy() ma zero uczestnikow", kurs->getUczestnicy().size() == 0);

    assertm("kurs->czyNalezy() dla nie dolaczonego studenta zwraca false", !kurs->czyNalezy(s1));
    assertm("kurs->dolacz() dla nie dolaczonego studenta zwraca true", kurs->dolacz(s1));
    assertm("kurs->czyNalezy() dla dolaczonego studenta zwraca true", kurs->czyNalezy(s1));
    assertm("kurs->dolacz() dla dolaczonego studenta zwraca false", !kurs->dolacz(s1));

    assertm("kurs->getUczestnicy() ma jednego uczestnika", kurs->getUczestnicy().size() == 1);

    assertm("kurs->getOcena() dla dolaczonego studenta bez oceny zwraca 0.f", kurs->getOcena(s1) == 0.f);
    assertm("kurs->setOcena() dla dolaczonego studenta zwraca true", kurs->setOcena(s1, 5.f));
    assertm("kurs->getOcena() dla dolaczonego studenta zwraca ocene", kurs->getOcena(s1) == 5.f);

    std::cout << "Kurs ALL OK!" << std::endl << std::endl;
}
