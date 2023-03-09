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
    jamnik->chaseTail();
    kicia->cleanYourself();


    delete[] jamnik;
    delete[] kicia;
    return 0;
}
