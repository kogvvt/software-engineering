//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : User.cpp
//  @ Date : 19.04.2023
//  @ Author : 
//
//


#include "User.h"

void User::login(InternetStoreSystem *internetStore) {
    internetStore->authenticate(this);
}

void User::printData() {
    cout <<"Username: " <<this->getUsername() <<endl;
}

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

void User::setID(int id) {
    this->id = id;
}

int User::getID() {
    return id;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

void User::setUsername(string username) {
    this->username = username;
}

void User::setPassword(string password) {
    this->password = password;
}
