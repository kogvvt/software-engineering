//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Newton.h
//  @ Date : 17.05.2023
//  @ Author : 
//
//


#if !defined(_NEWTON_H)
#define _NEWTON_H
#include "Factorial.h"

class Newton {
public:
	Newton();
	~Newton();
	long double newton(int n, int k, Factorial* factorial);
private:
	int N;
};

#endif  //_NEWTON_H
