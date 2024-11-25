#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <utility>
#include <initializer_list>
#include <string>
#include <algorithm>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
public:
    StrVec(): elements(nullptr), firstFree(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec&);
    StrVec& operator=(std::initializer_list<std::string>);
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t);
    void resize(size_t newSize, const std::string& s = std::string());
    std::string* begin() const;
    std::string* end() const;
private:
    std::allocator<std::string> alloc;
    void checkAndAlloc();
    std::pair<std::string*, std::string*> allocAndCopy(const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string* elements;
    std::string* firstFree;
    std::string* cap;
};

#endif