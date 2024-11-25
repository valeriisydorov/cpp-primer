#include <iostream>

int main(int argc, char **argv) {
    char *progName = argv[0];
    char *flag1 = argv[1];
    char *flag2 = argv[2];
    char *name1 = argv[3];
    char *name2 = argv[4];

    std::cout << "Parameter 1: " << progName << std::endl;
    std::cout << "Parameter 2: " << flag1 << std::endl;
    std::cout << "Parameter 3: " << flag2 << std::endl;
    std::cout << "Parameter 4: " << name1 << std::endl;
    std::cout << "Parameter 5: " << name2 << std::endl;

    return 0;
}