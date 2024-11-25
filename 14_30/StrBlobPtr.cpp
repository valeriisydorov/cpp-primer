#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr(StrBlob& a, size_t sz): wptr(a.data), curr(sz) { }

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string& msg) const {
    std::shared_ptr<std::vector<std::string>> ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return lhs.curr < rhs.curr;
}

std::string& StrBlobPtr::operator[](std::size_t n) {
    std::shared_ptr<std::vector<std::string>> p = wptr.lock();
    if (!p) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    return (*p)[n];
}

const std::string& StrBlobPtr::operator[](std::size_t n) const {
    std::shared_ptr<std::vector<std::string>> p = wptr.lock();
    if (!p) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    return (*p)[n];
}

StrBlobPtr& StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr* StrBlobPtr::operator+(std::size_t n) {
    StrBlobPtr* ret = this;
    ret->curr = ret->curr + n;
    check(ret->curr, "increment past end of StrBlobPtr");
    return ret;
}

StrBlobPtr* StrBlobPtr::operator-(std::size_t n) {
    StrBlobPtr* ret = this;
    ret->curr = ret->curr - n;
    check(ret->curr, "decrement past begin of StrBlobPtr");
    return ret;
}

std::string& StrBlobPtr::operator*() const {
    std::shared_ptr<std::vector<std::string>> p = check(curr, "dereference past end");
    return (*p)[curr];
}

std::string* StrBlobPtr::operator->() const {
    return &this->operator*();
}