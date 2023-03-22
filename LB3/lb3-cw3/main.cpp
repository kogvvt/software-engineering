#include "Company.h"
#include "Employee.h"


int main() {
    Company *company = new Company("SomeCompany");
    company->setEmployee(21,"Krzysztof Spoznialski");
    cout << "The company name is " << company->getCompanyName() <<" and one of its employees is "
    << company->getEmployee().getName() << " identified by ID number : " <<company->getEmployee().getID()<<endl;

    delete company;
    return 0;
}
