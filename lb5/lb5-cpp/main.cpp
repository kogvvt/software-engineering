#include "Company.h"

int main() {
    Company *company = new Company("KoguTech");
    company->hireEmployee(1,"Maciek",true,25000);
    company->hireEmployee(2,"Kasia",true,35000);
    company->hireEmployee(3,"Witold",true,50000);
    company->getManagers();
    company->hireEmployee(4,"Julia",false,10000);
    company->hireEmployee(5,"Maria",false,10000);
    company->hireEmployee(6,"Marek",false,10000);
    company->getEmployees();
    company->fireEmployeeWithID(5);
    cout << endl;
    company->getEmployees();
    Employee *juliusz = new Employee(5,"Juliusz", false, 4000);
    company->hireEmployee(*juliusz);
    Manager wit = company->getManagerByID(3);
    wit.getFullEmpInfo();
    wit.addEmployeeToTeam(*juliusz);
    cout<<endl;
    wit.getEmployees();
    cout<<endl;
    wit.setManagerAttrToEmpID(5, false);
    wit.getEmployees();
    cout<<endl;
    wit.fireEmployeeWithID(5);
    wit.setManagerAttrToEmpID(5, true);
    wit.fireEmployeeWithID(5);
    wit.getEmployees();
    company->fireEmployeeWithID(5);

    delete juliusz;
    delete company;
    return 0;
}
