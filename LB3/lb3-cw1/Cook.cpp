//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Cook.cpp
//  @ Date : 21.03.2023
//  @ Author : 
//
//


#include "Cook.h"
#include "Food.h"

Food Cook::createFood(string name, int id, int price) {
    Food result = Food(name,id,price);
    return result;
}

string Cook::getName() {
    return name;
}

void Cook::setName(string name) {
    this->name = name;
}

