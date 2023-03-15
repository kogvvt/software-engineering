#include <iostream>
#include "Ssak.h"
#include "KotNorweskiLesny.h"
#include "Kapibara.h"
#include "Jamnik.h"
#include "Pies.h"
using namespace std;
int main() {
    Pies* jamnik = new Jamnik(3,20,"Janusz","Brown",true,"dachshund",true);
    Kot* kicia = new KotNorweskiLesny(2,30,"Kicia","Black", true, true);
    Kapibara* janusz = new Kapibara(1,45,"Janusz","Brown",true);
    cout << "Cat is " << kicia->getAge() << " years old, has a " << kicia->getFurColor() << " fur color" <<endl;
    jamnik->chaseTail();
    kicia->cleanYourself();
    janusz->swim();

    delete jamnik;
    delete kicia;
    delete janusz;
    return 0;
}
