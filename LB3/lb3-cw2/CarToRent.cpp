//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : CarToRent.cpp
//  @ Date : 21.03.2023
//  @ Author : 
//
//


#include "CarToRent.h"
#include "Client.h"


Client* CarToRent::getClient() {
    return client;
}

void CarToRent::setClient(Client* client) {
    this->client = client;
}

string CarToRent::getName() {
    return name;
}

void CarToRent::setName(string name) {
    this->name = name;
}

CarToRent::CarToRent(string name) {
    this->name = name;
}
