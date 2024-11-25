#ifndef HASPTR_H
#define HASPTR_H

#include <string>
using std::string;

class HasPtr {
public:
    HasPtr(const string& s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr&);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr() {
        delete ps;
    }
private:
    string* ps;
    int i;
};

#endif
