//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Kapibara.h
//  @ Date : 15.03.2023
//  @ Author : 
//
//


#if !defined(_KAPIBARA_H)
#define _KAPIBARA_H

#include "Ssak.h"

class Kapibara : public Ssak {
public:
    Kapibara(int age, int height, string name, string furColor, bool hasWeb);
	bool hasWeb;
	void swim();
};

#endif  //_KAPIBARA_H
