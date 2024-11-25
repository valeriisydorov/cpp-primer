#include <iostream>
#include "CompareTemplate.h"

int main() {
    std::cout << compare<const char*>("hi", "hey") << std::endl;

    return 0;
}
