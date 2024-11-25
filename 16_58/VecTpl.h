#ifndef VECTPL_H
#define VECTPL_H


#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>


template <typename T> class Vec;
template <typename T> bool operator==(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator!=(const Vec<T>&, const Vec<T>&);
template <typename T> bool operator<(const Vec<T>&, const Vec<T>&);

template <typename T> class Vec {
    friend bool operator==(const Vec<T>&, const Vec<T>&);
    friend bool operator!=(const Vec<T>&, const Vec<T>&);
    friend bool operator<(const Vec<T>&, const Vec<T>&);
public:
    Vec(): elements(nullptr), firstFree(nullptr), cap(nullptr) { }
    Vec(const Vec<T>&);
    Vec(std::initializer_list<T>);
    Vec& operator=(const Vec<T>&);
    Vec(Vec<T>&&) noexcept;
    Vec& operator=(Vec<T>&&) noexcept;
    T& operator[](std::size_t);
    const T& operator[](std::size_t) const;
    ~Vec();
    void pushBack(const T&);
    template <class ... Args> void emplaceBack(Args&& ...);
    std::size_t size() const;
    std::size_t capacity() const;
    void reserve(std::size_t);
    void resize(std::size_t newSize, const T& s = T());
    T* begin() const;
    T* end() const;
private:
    std::allocator<T> alloc;
    void checkAndAlloc();
    std::pair<T*, T*> allocAndCopy(const T*, const T*);
    void free();
    void reallocate();
    T* elements;
    T* firstFree;
    T* cap;
};


template <typename T> Vec<T>::Vec(const Vec<T>& s) {
    std::pair<T*, T*> newdata = allocAndCopy(s.begin(), s.end());
    elements = newdata.first;
    firstFree = cap = newdata.second;
}

template <typename T> Vec<T>::Vec(std::initializer_list<T> il) {
    std::pair<T*, T*> newdata = allocAndCopy(il.begin(), il.end());
    elements = newdata.first;
    firstFree = cap = newdata.second;
}

template <typename T> Vec<T>& Vec<T>::operator=(const Vec<T>& rhs) {
    std::pair<T*, T*> data = allocAndCopy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    firstFree = cap = data.second;
    return *this;
}

template <typename T> Vec<T>::Vec(Vec<T>&& s) noexcept: elements(s.elements), firstFree(s.firstFree), cap(s.cap) {
    s.elements = s.firstFree = s.cap = nullptr;
}

template <typename T> Vec<T>& Vec<T>::operator=(Vec<T>&& rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        firstFree = rhs.firstFree;
        cap = rhs.cap;
        rhs.elements = rhs.firstFree = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T> T& Vec<T>::operator[](std::size_t n) {
    return elements[n];
}

template <typename T> const T& Vec<T>::operator[](std::size_t n) const {
    return elements[n];
}

template <typename T> Vec<T>::~Vec() {
    free();
}

template <typename T> void Vec<T>::pushBack(const T& s) {
    checkAndAlloc();
    alloc.construct(firstFree++, s);
}

template <typename T> std::size_t Vec<T>::size() const {
    return firstFree - elements;
}

template <typename T> std::size_t Vec<T>::capacity() const {
    return cap - elements;
}

template <typename T> void Vec<T>::reserve(std::size_t newSize) {
    if (newSize > capacity()) {
        T* newdata = alloc.allocate(newSize);
        T* dest = newdata;
        T* elem = elements;
        for (std::size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        firstFree = dest;
        cap = elements + newSize;
    }
}

template <typename T> void Vec<T>::resize(std::size_t newSize, const T& s) {
    if (newSize <= size()) {
        T* newdata = alloc.allocate(newSize);
        T* dest = newdata;
        T* elem = elements;
        for (std::size_t i = 0; i != newSize; ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        firstFree = cap = dest;
    } else {
        T* newdata = alloc.allocate(newSize);
        T* dest = newdata;
        T* elem = elements;
        for (std::size_t i = 0; i != newSize; ++i) {
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

template <typename T> T* Vec<T>::begin() const {
    return elements;
}

template <typename T> T* Vec<T>::end() const {
    return firstFree;
}

template <typename T> void Vec<T>::checkAndAlloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

template <typename T> std::pair<T*, T*> Vec<T>::allocAndCopy(const T* b, const T* e) {
    T* data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T> void Vec<T>::free() {
    if (elements) {
        for (T* p = firstFree; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T> void Vec<T>::reallocate() {
    std::size_t newcapacity = size() ? 2 * size() : 1;
    T* newdata = alloc.allocate(newcapacity);
    T* dest = newdata;
    T* elem = elements;
    for (std::size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    firstFree = dest;
    cap = elements + newcapacity;
}

template <typename T> bool operator==(const Vec<T>& lhs, const Vec<T>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T> bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T> bool operator<(const Vec<T>& lhs, const Vec<T>& rhs) {
    if (lhs.size() < rhs.size()) {
        return true;
    } else if (lhs.size() > rhs.size()) {
        return false;
    }
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T> template <class ... Args> inline void Vec<T>::emplaceBack(Args&& ... args) {
    checkAndAlloc();
    alloc.construct(firstFree++, std::forward<Args>(args)...);
}


#endif
