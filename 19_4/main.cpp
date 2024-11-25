#include <stdexcept>


class A
{
public:
    A() = default;
    virtual ~A() = default;
};

class B
: public A
{
public:
    B() = default;
    virtual ~B() = default;
};

class C
: public B
{
public:
    C() = default;
    virtual ~C() = default;
};

class D
: public B
, public A
{
public:
    D() = default;
    virtual ~D() = default;
};


int main()
{
    B* pa = new C;

    if (C* pc = dynamic_cast<C*>(pa))
    {
        C& rc = *pc;
    }
    else
    {
    }

    return 0;
}
