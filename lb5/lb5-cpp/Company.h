//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Company.h
//  @ Date : 30.03.2023
//  @ Author : 
//
//


#if !defined(_COMPANY_H)
#define _COMPANY_H
#include "Manager.h"

class Company {
public:
	string getCompanyName();
	void getManagers();
	void getEmployees();
	void setSalaryToEmployeeID(int id, int salary);
	void hireEmployee(int id, string name, bool isManager, int salary);
	void fireEmployeeWithID(int id);
	void setCompanyName(string name);
    Company(string companyName);
    ~Company();
    void hireEmployee(Employee employee);
    void hireManager(Manager manager);
    Employee getEmployeeByID(int id);
    Manager getManagerByID(int id);
private:
	vector<Manager> managers;
	vector<Employee> employees;
	string companyName;
    bool canManage = true;
};

#endif  //_COMPANY_H
