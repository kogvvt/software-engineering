#include <iostream>

#include "Wiadomosc.test.h"
#include "Uzytkownik.test.h"
#include "Kurs.test.h"
#include "Uczelnia.test.h"
 
int main() {
    uzytkownik_run_tests();
    wiadomosc_run_tests();
    kurs_run_tests();
    uczelnia_run_tests();

    std::cout << "ALL OK :)" << std::endl;
}