//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : A.cpp
//  @ Date : 17.05.2023
//  @ Author : 
//
//


#include "A.h"

void A::setB(B* b) {
    this->b = b;
}

void A::aFunction() {
    for(n = 0;n < 9;n++){
        b->bFunction();
    }
}

