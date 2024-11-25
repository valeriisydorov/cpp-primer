#include "HasPtr.h"

HasPtr::HasPtr(const std::string& s): ps(new std::string(s)), i(0) { }

HasPtr::HasPtr(const HasPtr& p): ps(new std::string(*p.ps)), i(p.i) { }

HasPtr::HasPtr(HasPtr&& p) noexcept: ps(p.ps), i(p.i) {
    p.ps = 0;
}

//HasPtr& HasPtr::operator=(const HasPtr& p) {
//    std::string* newp = new std::string(*p.ps);
//    delete ps;
//    ps = newp;
//    i = p.i;
//    return *this;
//}

HasPtr& HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

HasPtr::~HasPtr() {
    delete ps;
}

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    std::cout << "swap()" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}