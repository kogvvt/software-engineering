//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : User.cpp
//  @ Date : 21.03.2023
//  @ Author : 
//
//


#include "User.h"
#include "InternetProvider.h"

void User::connectToTheInternet(InternetProvider provider) {
    provider.connectToTheInternet();
}

string User::getName() {
    return name;
}

int User::getID() {
    return id;
}

void User::setName(string name) {
    this->name = name;
}

void User::setID(int id) {
    this->id = id;
}

