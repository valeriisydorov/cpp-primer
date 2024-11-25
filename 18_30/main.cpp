#include <iostream>


class Class 
{
public:
    Class() 
    { 
        std::cout << "Class()" << std::endl;
    }
    Class(const Class &)
    {
        std::cout << "Class(const Class&)" << std::endl;
    }
    Class(int)
    {
        std::cout << "Class(int)" << std::endl;
    }
};

class Base 
: public Class 
{
public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }
    Base(const Base& rhs)
    : ival(rhs.ival)
    {
        std::cout << "Base(const Base&)" << std::endl;
    }
    Base(int i)
    : ival(i)
    {
        std::cout << "Base(int)" << std::endl;
    }
private:
    int ival = 0;
};

class D1
: virtual public Base
{
public:
    D1()
    {
        std::cout << "D1()" << std::endl;
    }
    D1(const D1& rhs)
    : Base(rhs)
    {
        std::cout << "D1(const D1&)" << std::endl;
    }
    D1(int i)
    : Base(i)
    {
    }
};

class D2
: virtual public Base
{
public:
    D2()
    {
        std::cout << "D2()" << std::endl;
    }
    D2(const D2& rhs)
    : Base(rhs)
    {
        std::cout << "D2(const D2&)" << std::endl;
    }
    D2(int i)
    : Base(i)
    {
    }
};

class MI
: public D1
, public D2
{
public:
    MI()
    {
        std::cout << "MI()" << std::endl;
    }
    MI(const MI& rhs)
    : Base(rhs)
    , D1(rhs)
    , D2(rhs)
    {
        std::cout << "MI(const MI&)" << std::endl;
    }
    MI(int i)
    : Base(i)
    , D1(i)
    , D2(i)
    {
    }
};

class Final
: public MI
, public Class
{
public:
    Final()
    {
        std::cout << "Final()" << std::endl;
    }
    Final(const MI& rhs)
    : Base(rhs)
    , MI(rhs)
    , Class(rhs)
    {
        std::cout << "Final(const Final&)" << std::endl;
    }
    Final(int i)
    : Base(i)
    , MI(i)
    , Class(i)
    {
    }
};


int main()
{
    Final obj1(42);
    Final obj2(obj1);

    return 0;
}
