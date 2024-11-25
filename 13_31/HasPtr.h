#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& p): ps(new std::string(*p.ps)), i(p.i) { }
    HasPtr& operator=(const HasPtr&);
    bool operator<(const HasPtr& rhs) const {
        return *ps < *rhs.ps;
    }
    ~HasPtr();
private:
    std::string* ps;
    int i;
};

#endif
