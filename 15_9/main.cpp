#include <iostream>

class Base {
public:
    virtual void print() const {
        std::cout << "Base" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() const override {
        std::cout << "Derived" << std::endl;
    }
};

int main() {
    Base base;
    Derived derived;

    Base* basePtr = &derived;
    basePtr->print();

    Base& baseRef = derived;
    baseRef.print();

    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    derivedPtr->print();

    return 0;
}