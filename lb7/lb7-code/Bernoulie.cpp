//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Bernoulie.cpp
//  @ Date : 09.05.2023
//  @ Author : 
//
//


#include "Bernoulie.h"

void Bernoulie::countBernoulie(double p, int n, int k) {
    argQ = 1 - p;
    auto result = (pNewton->newton(n,k) *
            pPower->power(p,k) *
            pPower->power(argQ,n-k));
    cout <<pNewton->newton(n,k) <<endl;
    cout<<      pPower->power(p,k) <<endl;
    cout<< pPower->power(argQ,n-k) <<endl;
    cout << "Prawdopodobienstwo, ze w " << n << " doswiadczeniach "
        << k << " razy otrzymamy sukces wynosi " << result <<endl;

}

Bernoulie::Bernoulie() {
    pNewton = new Newton();
    pPower = new Power();
}

Bernoulie::~Bernoulie() {
    delete pNewton;
    delete pPower;
}

