#include <iostream>
#include <fstream>


int main()
{
    std::ifstream example("../example");

    const int length = 100;
    char buffer[length];

    while (example.getline(buffer, length))
    {
        std::cout << buffer << std::endl;
    }

    return 0;
}
