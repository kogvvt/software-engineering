//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Client.h
//  @ Date : 21.03.2023
//  @ Author : 
//
//


#if !defined(_CLIENT_H)
#define _CLIENT_H


#include "CarToRent.h"
#include <string>
using namespace std;
class CarToRent;
class Client {
private:
    int id;
    string name;
    CarToRent* rentedCar;
public:
	CarToRent* getRentedCar();
	void rentCar(CarToRent* rentedCar);
	int getID();
	string getName();
	void setID(int id);
	void setName(string name);
    Client(int id, string name);


};

#endif  //_CLIENT_H
