#pragma once


class Base
{
public:
    Base() noexcept;
    ~Base() noexcept;

    virtual double f1(double) noexcept;
    virtual int f2() noexcept(false);
    virtual void f3();
};