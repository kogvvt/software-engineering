//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Wiadomosc.cpp
//  @ Date : 24.05.2023
//  @ Author : 
//
//

#include "Wiadomosc.h"
#include "Uzytkownik.h"

Wiadomosc::Wiadomosc(Uzytkownik* nadawca, Uzytkownik* odbiorca, string temat, string tresc) {
    this->nadawca = nadawca;
    this->odbiorca = odbiorca;
    this->temat = temat;
    this->tresc = tresc;
}

Uzytkownik& Wiadomosc::getNadawca() {
    return *(this->nadawca);
}

Uzytkownik& Wiadomosc::getOdbiorca() {
    return *(this->odbiorca);
}

string Wiadomosc::getTemat() {
    return this->temat;
}

string Wiadomosc::getTresc() {
    return this->tresc;
}

