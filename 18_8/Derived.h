#pragma once


#include "Base.h"


class Derived : public Base
{
public:
    Derived() noexcept(true);
    ~Derived() noexcept(true);

    double f1(double) noexcept;
    int f2() noexcept(false);
    void f3() noexcept;
};
