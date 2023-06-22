#include "Coffee.h"
#include "Americano.h"
#include "Espresso.h"

int main() {
    Coffee *americano = new Americano();
    Coffee *espresso = new Espresso();

    cout<<"Concrete Class 1: Americano Coffee "<<endl;
    americano->brew();
    cout<<"==============================="<<endl;
    cout <<"Concrete Class 2: Espresso Coffee"<<endl;
    espresso->brew();
    return 0;
}
