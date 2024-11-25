#include <iostream>
#include "Person.h"

int main() {
    if (std::cin) {
        Person person{std::cin};
        print(std::cout, person) << std::endl;
    }
    return 0;
}
