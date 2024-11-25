#ifndef FOO_H
#define FOO_H

#include <vector>

class Foo {
public:
    Foo() = default;
    Foo(const std::vector<int>&);
    Foo(const Foo&);
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};


#endif
