#include "Company.h"
#include "Employee.h"

int main() {
    Company *company = new Company();
    company->employeePushBack(new Employee(3,"John Doe"));
    company->employeePushBack(new Employee(4,"Jan Kowalski"));
    company->employeePushBack(new Employee(5,"Janusz Przykladowski"));
    company->getEmployeeAtIndex(1);
    company->employeePopBack();
    company->employeePopBack();
    company->employeePopBack();
    delete company;
    return 0;
}
