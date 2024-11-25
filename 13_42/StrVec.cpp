#include "StrVec.h"

StrVec::StrVec(const StrVec& s) {
    std::pair<std::string*, std::string*> newdata = allocAndCopy(s.begin(), s.end());
    elements = newdata.first;
    firstFree = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    std::pair<std::string*, std::string*> newdata = allocAndCopy(il.begin(), il.end());
    elements = newdata.first;
    firstFree = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
    std::pair<std::string*, std::string*> data = allocAndCopy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    firstFree = cap = data.second;
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string& s) {
    checkAndAlloc();
    alloc.construct(firstFree++, s);
}

size_t StrVec::size() const {
    return firstFree - elements;
}

size_t StrVec::capacity() const {
    return cap - elements;
}

void StrVec::reserve(size_t newSize) {
    if (newSize > capacity()) {
        std::string* newdata = alloc.allocate(newSize);
        std::string* dest = newdata;
        std::string* elem = elements;
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        firstFree = dest;
        cap = elements + newSize;
    }
}

void StrVec::resize(size_t newSize, const std::string& s) {
    if (newSize <= size()) {
        std::string* newdata = alloc.allocate(newSize);
        std::string* dest = newdata;
        std::string* elem = elements;
        for (size_t i = 0; i != newSize; ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        firstFree = cap = dest;
    } else {
        std::string* newdata = alloc.allocate(newSize);
        std::string* dest = newdata;
        std::string* elem = elements;
        for (size_t i = 0; i != newSize; ++i) {
            if (i != size()) {
                alloc.construct(dest++, std::move(*elem++));
            } else {
                alloc.construct(dest++, s);
            }
        }
        free();
        elements = newdata;
        firstFree = dest;
        cap = elements + newSize;
    }
}

std::string* StrVec::begin() const {
    return elements;
}

std::string* StrVec::end() const {
    return firstFree;
}

void StrVec::checkAndAlloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

std::pair<std::string*, std::string*> StrVec::allocAndCopy(const std::string* b, const std::string* e) {
    std::string* data = alloc.allocate(e - b);

    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (std::string* p = firstFree; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    size_t newcapacity = size() ? 2 * size() : 1;
    std::string* newdata = alloc.allocate(newcapacity);
    std::string* dest = newdata;
    std::string* elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    firstFree = dest;
    cap = elements + newcapacity;
}
