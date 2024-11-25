#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <cstring>
#include <memory>
#include <iostream>
#include <algorithm>

class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    friend bool operator<(const String&, const String&);
public:
    String() = default;
    String(char*);
    String(const String&);
    String& operator=(const String&);
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;
    ~String();

    char* begin() const;
    char* end() const;
    std::size_t size() const;
    bool empty() const;
    void append(const char*);
private:
    std::allocator<char> alloc;
    char* cp = nullptr;
    std::size_t sz = 0;

    void free();
};

#endif
