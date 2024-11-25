#include "ConstStrBlobPtr.h"

const std::string& ConstStrBlobPtr::operator*() const {
    std::shared_ptr<const std::vector<std::string>> p = check(curr, "dereference past end");
    return (*p)[curr];
}

const std::string* ConstStrBlobPtr::operator->() const {
    return &this->operator*();
}