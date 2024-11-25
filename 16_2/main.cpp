#include <iostream>
#include <vector>
#include <string>
#include "CompareTemplate.h"


int main() {
    int i1 = 2;
    int i2 = 7;
    std::cout << compare(i1, i2) << std::endl;

    double d1 = 3.14;
    double d2 = 2.7;
    std::cout << compare(d1, d2) << std::endl;

    std::vector<std::string> vec1{"Valerii"};
    std::vector<std::string> vec2{"Arina"};
    std::cout << compare(vec1, vec2) << std::endl;

    return 0;
}
