//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Power.cpp
//  @ Date : 09.05.2023
//  @ Author : 
//
//


#include "Power.h"

double Power::power(double n, int m) {
    return m==0 ? 1.0 : n * power(n,m-1);
}

