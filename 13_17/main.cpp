#include <iostream>

#include "Numbered1.h"
#include "Numbered2.h"

void f(Numbered1 s) {
    std::cout << s.mysn << std::endl;
}

void f(Numbered2 s) {
    std::cout << s.mysn << std::endl;
}

int main() {
    Numbered2 a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
