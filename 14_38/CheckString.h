#ifndef CHECKSTRING_H
#define CHECKSTRING_H

#include <string>

class CheckString {
public:
    CheckString(size_t n): size(n) {}
    bool operator()(const std::string&) const;
private:
    size_t size;
};

#endif
