//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Ssak.h
//  @ Date : 09.03.2023
//  @ Author : 
//
//


#if !defined(_SSAK_H)
#define _SSAK_H
#include <string>
using namespace std;


class Ssak {
public:
	int getAge();
	int getHeight();
	string getName();
	void setAge(int value);
	void setHeight(int height);
	void setName(string name);
	string eat(string food);
	string getFurColor();
	void setFurColor(string furColor);
	void makeNoise();
private:
	int age;
	int height;
	string name;
	string furColor;
};

#endif  //_SSAK_H
