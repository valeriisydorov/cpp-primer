#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string& s = std::string());
    HasPtr(const HasPtr&);
    HasPtr(HasPtr&&) noexcept;
//    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(HasPtr);
    ~HasPtr();
private:
    std::string* ps;
    int i;
};

#endif
