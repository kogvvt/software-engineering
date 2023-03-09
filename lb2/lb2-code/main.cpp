#include <iostream>
#include "Ssak.h"
#include "KotNorweskiLesny.h"
#include "Kapibara.h"
#include "Jamnik.h"
#include "Pies.h"
using namespace std;
int main() {
    Pies* jamnik = new Jamnik();
    Kot* kicia = new KotNorweskiLesny();
    Kapibara* janusz = new Kapibara();
    kicia->setAge(3);
    kicia->setFurColor("black");
    kicia->setHeight(10);
    cout << "Cat is " << kicia->getAge() << " years old, has a " << kicia->getFurColor() << " fur color and eats " << kicia->eat("fish") <<endl;
    jamnik->chaseTail();
    kicia->cleanYourself();


    delete jamnik;
    delete kicia;
    delete janusz;
    return 0;
}
