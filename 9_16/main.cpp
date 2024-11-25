#include "CompareElements.h"
#include <iostream>

int main() {
    std::list<int> l1 = {0, 1, 2, 3, 4, 5};
    std::list<int> l2 = {0, 1, 2};
    std::vector<int> v1 = {0, 1, 2, 3, 4, 5};
    std::vector<int> v2 = {3, 4, 5};

    std::cout << std::boolalpha << compareElements(l1, v1) << std::endl;
    std::cout << std::boolalpha << compareElements(l2, v2) << std::endl;

    return 0;
}
