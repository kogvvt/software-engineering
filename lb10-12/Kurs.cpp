//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Kurs.cpp
//  @ Date : 24.05.2023
//  @ Author :
//
//

#include <algorithm>
#include "Kurs.h"
#include "Student.h"
#include "Wykladowca.h"

Kurs::Kurs(int id, string nazwa, Wykladowca* prowadzacy) {
    this->id = id;
    this->nazwa = nazwa;
    this->prowadzacy = prowadzacy;
}

bool Kurs::dolacz(Student* student) {
    // TODO: Sprawdzanie czy rejestracja na kurs jest otwarta, czy student jest na odpowiednim roku itd...
    if (this->czyNalezy(student)) {
        return false;
    }

    this->uczestnicy.push_back(student);
    this->oceny[student] = 0.f;
    return true;
}

void Kurs::wyswietlStudentow() {
    printf("Uczestnicy kursu '%s':\n", this->getNazwa().c_str());

    for (Student* student : this->uczestnicy) {
        printf("\t[%s] %s\n", student->getLogin().c_str(), student->getNazwisko().c_str());
    }
}

void Kurs::wyswietlWykladowce() {
    printf("Wykladowca kursu '%s':\n", this->getNazwa().c_str());
    printf("\t[%s] %s\n", this->getProwadzacy().getLogin().c_str(), this->getProwadzacy().getNazwisko().c_str());
}

void Kurs::wyswietlOceny() {
    printf("Oceny uczestnikow kursu '%s':\n", this->getNazwa().c_str());

    for (const std::pair<Student*, float>& v : this->oceny) {
        float ocena = v.second;
        if (ocena == 0.0f) {
            printf("\t[%s] %s: Brak oceny\n", v.first->getLogin().c_str(), v.first->getNazwisko().c_str());
        } else {
            printf("\t[%s] %s: %.1f\n", v.first->getLogin().c_str(), v.first->getNazwisko().c_str(), ocena);
        }
    }
}

bool Kurs::czyNalezy(Student* student) {
    return std::find(this->uczestnicy.begin(), this->uczestnicy.end(), student) != this->uczestnicy.end();
}

void Kurs::setNazwa(string nazwa) {
    // TODO: Sprawdzanie czy użytkownik wysyłajacy żądanie jest prowadzącym...
    this->nazwa = nazwa;
}

bool Kurs::setOcena(Student* student, float ocena) {
    // TODO: Sprawdzanie czy użytkownik wysyłajacy żądanie jest prowadzącym...
    if (this->czyNalezy(student)) {
        this->oceny[student] = ocena;
        return true;
    } else {
        return false;
    }
}

float Kurs::getOcena(Student* student) {
    if (this->czyNalezy(student)) {
        return this->oceny[student];
    } else {
        return -1.f;
    }
}

int Kurs::getId() {
    return this->id;
}

string Kurs::getNazwa() {
    return this->nazwa;
}

Wykladowca& Kurs::getProwadzacy() {
    return *(this->prowadzacy);
}

vector<Student*> Kurs::getUczestnicy() {
    return this->uczestnicy;
}
