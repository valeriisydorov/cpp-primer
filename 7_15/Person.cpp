#include <iostream>
using std::istream;
using std::ostream;

#include "Person.h"

istream &read(istream &is, Person &item)
{
    is >> item.name >> item.address;
    return is;
}

ostream &print(ostream &os, const Person &item)
{
    os << "Name: " << item.getName() << " Address: " << item.getAddress();
    return os;
}

Person::Person(std::istream &is) {
    read(is, *this);
}
