#include "Wiadomosc.test.h"

#include <iostream>

#include "../Student.h"
#include "../Wiadomosc.h"
 
void wiadomosc_run_tests() {
    std::cout << "Tests: Wiadomosc" << std::endl;

    Student* s1 = new Student("student1", "haslo1", "Imie Nazwisko");
    Student* s2 = new Student("student2", "haslo2", "Imie Nazwisko");

    Wiadomosc* wiadomosc = new Wiadomosc(s1, s2, "Temat", "Lorem Ipsum");

    assertm("wiadomosc->getNadawca() zwraca nadawce", wiadomosc->getNadawca().getLogin() == s1->getLogin());
    assertm("wiadomosc->getOdbiorca() zwraca odbiorce", wiadomosc->getOdbiorca().getLogin() == s2->getLogin());
    assertm("wiadomosc->getTemat() zwraca temat", wiadomosc->getTemat() == "Temat");
    assertm("wiadomosc->getTresc() zwraca tresc", wiadomosc->getTresc() == "Lorem Ipsum");

    std::cout << "Wiadomosc ALL OK!" << std::endl << std::endl;
}