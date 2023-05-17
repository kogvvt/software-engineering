#include "Bernoulie.h"

int main() {
    double p;
    int n, k;
    cout << " Podaj p: ";
    cin >> p;
    cout << " Podaj n: ";
    cin >> n;
    cout << " Podaj k: ";
    cin >> k;
    Bernoulie *bernoulie = new Bernoulie();
    Power *power = new Power();
    Newton *newton = new Newton();
    Factorial *factorial = new Factorial();
    bernoulie->countBernoulie(p,n,k,power,newton,factorial);
    delete bernoulie;
    delete power;
    delete newton;
    delete factorial;
    return 0;
}
