#include "A.h"

int main() {
    A a;
    B b;
    C c;
    a.setB(&b);
    b.setC(&c);
    c.setB(&b);
    a.aFunction();
    return 0;
}
