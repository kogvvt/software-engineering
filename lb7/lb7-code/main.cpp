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
    bernoulie->countBernoulie(p,n,k);
    delete bernoulie;
    return 0;
}
