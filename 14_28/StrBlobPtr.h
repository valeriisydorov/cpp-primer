#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <string>
#include <vector>
#include <memory>

class StrBlob;

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob& a, size_t sz = 0);
    std::string& operator[](std::size_t);
    const std::string& operator[](std::size_t) const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr* operator+(std::size_t);
    StrBlobPtr* operator-(std::size_t);
private:
    std::shared_ptr<std::vector<std::string>> check(size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

#endif
