#include "String.h"

String::String(char* str): sz(std::strlen(str)), cp(alloc.allocate(sz)) {
    std::uninitialized_copy(str, str + sz, cp);
}

String::String(const String &str): sz(str.sz), cp(alloc.allocate(str.sz)) {
    std::uninitialized_copy(str.cp, str.cp + sz, cp);
}

String& String::operator=(const String& rhs) {
    char* newcp = alloc.allocate(rhs.sz);
    std::uninitialized_copy(rhs.cp, rhs.cp + rhs.sz, newcp);
    if (cp) {
        alloc.deallocate(cp, sz);
    }
    cp = newcp;
    sz = rhs.sz;
    return *this;
}

String::~String() {
    free();
}

char* String::begin() const {
    return cp;
}

char* String::end() const {
    return cp + sz;
}

std::size_t String::size() const {
    return sz;
}

bool String::empty() const {
    return cp == nullptr;
}

void String::append(const char* str) {
    size_t len = strlen(str);
    char* temp = alloc.allocate(sz + len);
    std::uninitialized_copy(cp, cp + sz, temp);
    std::uninitialized_copy(str, str + len, temp + sz);

    free();
    cp = temp;
    sz += len;
}

void String::free() {
    if (cp != nullptr) {
        alloc.deallocate(cp, sz);
        cp = nullptr;
        sz = 0;
    }
}
