#include "String.h"

String::String(char* str): sz(std::strlen(str)), cp(alloc.allocate(sz)) {
    std::uninitialized_copy(str, str + sz, cp);
}

String::String(const String &str): sz(str.sz), cp(alloc.allocate(str.sz)) {
    std::cout << "String(const String&)" << std::endl;
    std::uninitialized_copy(str.cp, str.cp + sz, cp);
}

String& String::operator=(const String& rhs) {
    std::cout << "String::operator=(const String&)" << std::endl;
    char* newcp = alloc.allocate(rhs.sz);
    std::uninitialized_copy(rhs.cp, rhs.cp + rhs.sz, newcp);
    if (cp) {
        alloc.deallocate(cp, sz);
    }
    cp = newcp;
    sz = rhs.sz;
    return *this;
}

String::String(String&& str) noexcept: alloc(std::move(str.alloc)), cp(str.cp), sz(str.sz) {
    str.cp = nullptr;
    str.sz = 0;
}

String& String::operator=(String&& rhs) noexcept {
    if (this != &rhs) {
        free();
        alloc = std::move(rhs.alloc);
        cp = rhs.cp;
        sz = rhs.sz;
        rhs.cp = nullptr;
        rhs.sz = 0;
    }
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

std::ostream& operator<<(std::ostream& os, const String& s) {
    for (char* beg = s.begin(); beg != s.end(); ++beg) {
        os << *beg;
    }
    return os;
}

bool operator==(const String& lhs, const String& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}