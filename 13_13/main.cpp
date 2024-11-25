#include "X.h"

void f1(X& x) {
    X* a = new X;
    X b(*a);
    delete a;
}

void f2(X& a) {
    X z;
    X b(a);
}

void f3(X* a) {
    X b;
    b = *a;
    delete a;
}

int main() {
//    X a;
//    X b;
//    X c(a);
//    b = a;

//    f1(a);
//    f2(a);
    f3(new X);

    return 0;
}
