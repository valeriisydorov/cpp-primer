#ifndef STRBLOBPTRHOLD_H
#define STRBLOBPTRHOLD_H

#include "StrBlobPtr.h"

#include <memory>

class StrBlobPtr;

class StrBlobPtrHolder {
public:
    StrBlobPtrHolder(std::shared_ptr<StrBlobPtr> ptr): holder(ptr) {}
    StrBlobPtr* operator->() const;
private:
    std::shared_ptr<StrBlobPtr> holder;
};

#endif
