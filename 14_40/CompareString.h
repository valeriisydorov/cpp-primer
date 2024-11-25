#ifndef COMPARESTRING_H
#define COMPARESTRING_H

#include <string>

class CompareString {
public:
    CompareString() = default;
    CompareString(size_t n): size(n) {}
    bool operator()(const std::string&) const;
    bool operator()(const std::string&, const std::string&) const;
private:
    size_t size;
};

#endif
