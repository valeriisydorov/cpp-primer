#include <iostream>

#include "Foo.h"

int main() {
    std::vector<int> v1 = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    Foo f1(v1);
    Foo f2 = f1.sorted();


    return 0;
}
