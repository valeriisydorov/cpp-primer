#include <iostream>
#include <iomanip>
#include <cmath>


int main()
{
    std::cout << "boolalpha: " << std::boolalpha << true << " " << false << std::endl;
    std::cout << std::noboolalpha;

    std::cout << "showbase & uppercase: " << std::showbase << std::uppercase << std::oct << 32 << " " << std::hex << 32 << std::endl;
    std::cout << std::dec << std::noshowbase << std::nouppercase;

    std::cout.precision(10);
    std::cout << "showpoint & precision: " << std::showpoint <<  1.0 << std::endl;
    std::cout << std::noshowpoint;
    std::cout.precision();

    std::cout << "showpos: " << std::showpos << 1 << std::noshowpos << std::endl;

    std::cout << "scientific & hexfloat: " << std::scientific << std::sqrt(2) << " " << std::hexfloat << std::sqrt(2) << std::endl;
    std::cout << std::defaultfloat;

    std::cout << "setw, left, setfill: " << std::left << std::setfill('.') << std::setw(10) << 2.71828 << std::endl;
    std::cout << std::right << std::setfill(' ');

    return 0;
}
