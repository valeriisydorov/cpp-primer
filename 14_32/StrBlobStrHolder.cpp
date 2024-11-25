#include "StrBlobPtrHolder.h"

StrBlobPtr* StrBlobPtrHolder::operator->() const {
    return holder.get();
}