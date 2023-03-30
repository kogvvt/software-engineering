//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Manager.h
//  @ Date : 30.03.2023
//  @ Author : 
//
//


#if !defined(_MANAGER_H)
#define _MANAGER_H
#include "Employee.h"

class Manager : public Employee {
public:
	void setManagerAttrToEmpID(int id, bool isManager);
	void fireEmployeeWithID(int id);
    Manager(int id, const string &name, bool isManager, int salary);
    void addEmployeeToTeam(Employee emp);
    void getEmployees();
private:
    vector<Employee> employees;
    bool isManager = true;
};

#endif  //_MANAGER_H