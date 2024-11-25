#include <iostream>
#include <stdexcept>
#include <cstdlib>


int main()
{
    try
    {
        throw std::runtime_error("error");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;

        std::abort();
    }

    return 0;
}