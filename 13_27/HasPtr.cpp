#include "HasPtr.h"

HasPtr& HasPtr::operator=(const HasPtr &p) {
    ++*p.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;
    return *this;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}