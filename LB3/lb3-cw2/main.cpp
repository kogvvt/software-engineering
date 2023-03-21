#include <iostream>
#include "Client.h"
#include "CarToRent.h"
using namespace std;
int main() {
    Client *user = new Client(1,"Maciek");
    CarToRent *car = new CarToRent("Volvo");
    user->rentCar(car);
    car->setClient(user);
    cout << "User " <<user->getName()<< " has rented a "<< user->getRentedCar()->getName() << " car" <<endl;
    cout << "A " << car->getName() <<" has been rented by a user named " <<car->getClient()->getName() <<endl;
    delete user;
    delete car;
    return 0;
}
