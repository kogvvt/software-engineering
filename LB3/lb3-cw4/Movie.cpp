//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Movie.cpp
//  @ Date : 22.03.2023
//  @ Author : 
//
//


#include "Movie.h"

Movie::Movie() {
    cout<< "Made a movie record!" <<endl;
}

Movie::~Movie() {
    cout<<"Deleted a movie record!" <<endl;
}

string Movie::getMovieTitle() {
    return movieTitle;
}

string Movie::getMovieHour() {
    return movieHour;
}

void Movie::setMovieTitle(string movieTitle) {
    this->movieTitle = movieTitle;
}

void Movie::setMovieHour(string movieHour) {
    this->movieHour = movieHour;
}
