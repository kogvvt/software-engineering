//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Employee.h
//  @ Date : 30.03.2023
//  @ Author : 
//
//


#if !defined(_EMPLOYEE_H)
#define _EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
	int getID();
	string getName();
	bool getManagerInfo();
	int getSalary();
	void setID(int id);
	void setName(string name);
	Employee(int id, string name, bool isManager, int salary);
    void getFullEmpInfo();
    void setManagement(bool isManager, bool auth);
    void setSalary(int salary, bool auth);
private:
	int id;
	string name;
	bool isManager;
	int salary;
};

#endif  //_EMPLOYEE_H
