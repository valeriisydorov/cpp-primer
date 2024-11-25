#include <iostream>
#include "FlipTpl.h"

void printArgs(int a, long long b) {
    std::cout << "First argument: " << a << std::endl;
    std::cout << "Second argument: " << b << std::endl;
}

int main() {
    flip<void(*)(int, long long), int, long long >(printArgs, 42, 1000000000);

    return 0;
}