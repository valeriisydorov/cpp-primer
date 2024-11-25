#include "HasPtr.h"

HasPtr::HasPtr(const HasPtr& other) : ps(new string(*(other.ps))), i(other.i) {}

HasPtr& HasPtr::operator=(const HasPtr& other) {
    ps = new string(*(other.ps));
    i = other.i;
    return *this;
}