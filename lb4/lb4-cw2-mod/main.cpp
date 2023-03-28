#include <iostream>
#include "Client.h"
#include "CarToRent.h"
using namespace std;
int main() {
    Client *maciek = new Client(1,"Maciek");
    Client *marek = new Client(2,"Marek");
    CarToRent *volvo = new CarToRent("Volvo");
    CarToRent *ford = new CarToRent("Ford");
    CarToRent *toyota = new CarToRent("Toyota");
    CarToRent *alfa = new CarToRent("Alfa Romeo");
    CarToRent *seat = new CarToRent("Seat Leon");
    maciek->rentCar(volvo);
    maciek->rentCar(seat);
    maciek->rentCar(ford);
    marek->rentCar(toyota);
    marek->rentCar(alfa);
    marek->getAllRentedCars();
    marek->releaseAllCars();
    maciek->getAllRentedCars();
    maciek->releaseAllCars();


    delete maciek;
    delete marek;
    delete toyota;
    delete volvo;
    delete ford;
    delete alfa;
    delete seat;
    return 0;
}
