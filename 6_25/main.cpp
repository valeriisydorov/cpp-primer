#include <iostream>
#include <string>

int main(int argc, char **argv) {
    std::string arg1 = argv[1];
    std::string arg2 = argv[2];
    std::cout << arg1 + arg2 << std::endl;

    return 0;
}