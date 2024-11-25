#include <iostream>
#include <iomanip>
#include <cmath>


int main()
{
    std::cout << std::setfill('.');
    std::cout << std::setw(30) << std::left << "scientific:" << std::right << std::scientific << std::sqrt(2) << '\n';
    std::cout << std::setw(30) << std::left << "fixed decimal:" << std::right << std::fixed << std::sqrt(2) << '\n';
    std::cout << std::setw(30) << std::left << "hexadecimal:" << std::right << std::hexfloat << std::sqrt(2) << '\n';
    std::cout << std::setw(30) << std::left << "default:" << std::right << std::defaultfloat << std::sqrt(2) << '\n';
    std::cout << std::setfill(' ');

    return 0;
}