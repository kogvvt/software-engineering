//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Power.cpp
//  @ Date : 17.05.2023
//  @ Author : 
//
//


#include "Power.h"

double Power::power(double n, int m) {
    double result = 1;
    for (int i = 0; i < m; i++){
        result = result * n;
    }
    return result;
}
