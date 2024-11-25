class Base {

};

class Derived : public Base {

};

int main() {
    // static types
    Base base;
    Derived derived;

    // dynamic types
    Base* basePtr = &base;
    Base* derivedPtr = &derived;

    Base& baseRef = base;
    Base& derivedRef = derived;

    return 0;
}
