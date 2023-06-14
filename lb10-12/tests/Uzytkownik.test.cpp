#include "Uzytkownik.test.h"

#include <iostream>

#include "../Uzytkownik.h"
#include "../Student.h"
#include "../Wykladowca.h"
 
void uzytkownik_run_tests() {
    std::cout << "Tests: Uzytkownik/Student/Wykladowca" << std::endl;
    Student* s1 = new Student("student1", "haslo", "Imie Nazwisko");
    Wykladowca* w1 = new Wykladowca("wykladowca1", "haslo", "Imie Nazwisko");

    Uzytkownik* u_student = s1;
    Uzytkownik* u_wykladowca = w1;

    assertm("uzytkownik->getLogin() zwraca login", s1->getLogin() == "student1");
    assertm("uzytkownik->getHaslo() zwraca haslo", s1->getHaslo() == "haslo");
    assertm("uzytkownik->getNazwisko() zwraca nazwisko", s1->getNazwisko() == "Imie Nazwisko");

    s1->setHaslo("nowehaslo");
    s1->setNazwisko("Nowe Nazwisko");
    assertm("uzytkownik->getHaslo() po zmianie hasla", s1->getHaslo() == "nowehaslo");
    assertm("uzytkownik->getNazwisko() po zmianie nazwiska", s1->getNazwisko() == "Nowe Nazwisko");

    assertm("dynamic_cast<Student> dla Uzytkownika studenta", dynamic_cast<Student*>(u_student) != nullptr);
    assertm("dynamic_cast<Wykladowca> dla Uzytkownika wykladowcy", dynamic_cast<Wykladowca*>(u_wykladowca) != nullptr);

    assertm("dynamic_cast<Student> dla Uzytkownika wykladowcy", dynamic_cast<Student*>(u_wykladowca) == nullptr);
    assertm("dynamic_cast<Wykladowca> dla Uzytkownika studenta", dynamic_cast<Wykladowca*>(u_student) == nullptr);

    std::cout << "Uzytkownik/Student/Wykladowca ALL OK!" << std::endl << std::endl;
}