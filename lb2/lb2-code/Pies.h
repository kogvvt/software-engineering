//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Pies.h
//  @ Date : 15.03.2023
//  @ Author : 
//
//


#if !defined(_PIES_H)
#define _PIES_H

#include "Ssak.h"
using namespace std;

class Pies : public Ssak {
public:
    Pies(int age, int height, string name, string furColor, bool isMixed, string race);
	bool isMixed;
	void chaseTail();
	string getRace();
	void setRace(string race);
private:
	string race;
};

#endif  //_PIES_H
