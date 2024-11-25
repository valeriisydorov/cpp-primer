#include <typeinfo>
#include <iostream>


#include "Sales_data.h"
#include <string>


class Base
{
public:
    virtual ~Base() = default;
};

class Derived
: public Base
{
};


int main()
{
    int i = 42;
    int arr[10];
    Derived d;
    Base *p = &d;

    std::cout << "1. int: " << typeid(i).name() << "\n"
              << "2. int arr[10]: " << typeid(arr).name() << "\n"
              << "3. Sales_data: " << typeid(Sales_data).name() << "\n"
              << "4. std::string: " << typeid(std::string).name() << "\n"
              << "5. Base: " << typeid(p).name() << "\n"
              << "6. Derived: " << typeid(*p).name() << std::endl;

    return 0;
}
