//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Movie.cpp
//  @ Date : 23.03.2023
//  @ Author : 
//
//


#include "Movie.h"

Movie::Movie(string movieTitle, string movieHour) {
    this->movieTitle = movieTitle;
    this->movieHour = movieHour;
}

Movie::~Movie() {

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

