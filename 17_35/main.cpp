#include <iostream>
#include <cmath>


int main()
{
    std::cout << std::uppercase << std::hexfloat << std::sqrt(2) << std::endl;
    std::cout << std::nouppercase << std::defaultfloat;

    return 0;
}