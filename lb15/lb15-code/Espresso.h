//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Espresso.h
//  @ Date : 22.06.2023
//  @ Author : 
//
//


#if !defined(_ESPRESSO_H)
#define _ESPRESSO_H

#include "Coffee.h"

class Espresso : public Coffee {
public:
	void brewCoffee() override;
	void addCondiments() override;
    bool customerWantsCondiments() override;
};

#endif  //_ESPRESSO_H
