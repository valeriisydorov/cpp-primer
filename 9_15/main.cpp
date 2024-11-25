#include "CompareVectors.h"
#include <iostream>

int main() {
    std::vector<int> v1 = {0, 1, 2, 3, 4, 5};
    std::vector<int> v2 = {0, 1, 2, 3, 4, 5};
    std::vector<int> v3 = {0, 1, 2};

    std::cout << std::boolalpha << compareVectors(v1, v2) << std::endl;
    std::cout << std::boolalpha << compareVectors(v3, v2) << std::endl;

    return 0;
}
