#include "Foo.h"

#include <algorithm>

Foo::Foo(const std::vector<int>& input) : data(input) { }
Foo::Foo(const Foo& other) : data(other.data) { }

Foo Foo::sorted() && {
    std::sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
//    Foo ret(*this);
//    std::sort(ret.data.begin(), ret.data.end());
//    return ret;

//    return ret.sorted();
    return Foo(*this).sorted();

}
