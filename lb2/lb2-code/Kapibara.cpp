//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Kapibara.cpp
//  @ Date : 15.03.2023
//  @ Author : 
//
//

#include <iostream>
#include "Kapibara.h"
using namespace std;
Kapibara::Kapibara(int age, int height, string name, string furColor, bool hasWeb)
: Ssak(age,height,name,furColor){
    this->hasWeb = hasWeb;
}
void Kapibara::swim() {
    cout << "The capybara is swimming"<<endl;
}

