#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


int main()
{
    std::ifstream example("../example");

    const int length = 100;
    char buffer[length];

    while (example.getline(buffer, length))
    {
        std::istringstream iss(buffer);
        std::string word;
        while (iss >> word)
        {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
