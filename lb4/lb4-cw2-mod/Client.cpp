//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Client.cpp
//  @ Date : 28.03.2023
//  @ Author : 
//
//


#include "Client.h"

void Client::getRentedCarAtIndex(int i) {
    cout << "The rented car at index " <<i<< " is a " <<rentedCars.at(i+1)->getName()<<endl;
}

void Client::rentCar(CarToRent* rentedCar) {
    if(rentedCars.size()>1){
        cout<<"You can't have more than two cars at the same time!" <<endl;
    }else{
        rentedCars.push_back(rentedCar);
    }
}

int Client::getID() {
    return id;
}

string Client::getName() {
    return name;
}

void Client::setID(int id) {
    this->id = id;
}

void Client::setName(string name) {
    this->name = name;
}

Client::Client(int id, string name) {
    this->id = id;
    this->name = name;
}

void Client::getAllRentedCars() {
    int i = 1;
    cout << this->getName() << ", you have a :" <<endl;
    for (const auto &rentedCar: rentedCars) {
        cout <<"Car number " << i << " " << rentedCar->getName() <<endl;
        i++;
    }
}

void Client::releaseAllCars() {
    rentedCars.clear();
}

void Client::releaseCarNumber(int i) {
    rentedCars.erase(rentedCars.begin()+(i-1));
}
