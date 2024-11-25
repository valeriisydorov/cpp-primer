#include <stdexcept>
#include <iostream>


class exceptionType
{
};


int main()
{
    try
    {
        throw new exceptionType();
    }
    catch (exceptionType* pet)
    {
        std::cout << "Caught exceptionType pointer." << std::endl;
    }

    try
    {
        throw std::logic_error("Does not compute.");
    }
    catch (...)
    {
        std::cout << "Caught any exception." << std::endl;
    }

    typedef int EXCPTYPE;

    try {
        throw 42;
    }
    catch (EXCPTYPE e)
    {
        std::cout << "Caught EXCPTYPE: " << e << std::endl;
    }
    

    return 0;
}
