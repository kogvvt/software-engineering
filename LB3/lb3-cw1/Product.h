//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Product.h
//  @ Date : 16.03.2023
//  @ Author : 
//
//


#if !defined(_PRODUCT_H)
#define _PRODUCT_H
#include <string>
using namespace std;


class Product {
public:
	string getName();
	void setName(string name);
	int getID();
	Product(int id, string name);
	string getProductNameByID(int id);
    void setID(int id);
private:
	int id;
	string name;
};

#endif  //_PRODUCT_H
