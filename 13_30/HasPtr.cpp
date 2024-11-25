#include "HasPtr.h"

HasPtr& HasPtr::operator=(const HasPtr &p) {
    std::string* newp = new std::string(*p.ps);
    delete ps;
    ps = newp;
    i = p.i;
    return *this;
}

HasPtr::~HasPtr() {
    delete ps;
}

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap()" << std::endl;
}