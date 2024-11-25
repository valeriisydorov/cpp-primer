#ifndef BLOBPTRTPL_H
#define BLOBPTRTPL_H


#include <memory>
#include <vector>
#include <string>

template <typename T> class Blob;
template <typename T> class BlobPtr;

template <typename T> class BlobPtr {
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T>& a, size_t sz = 0): wptr(a.data), curr(sz) { }
    T& operator*() const {
        std::shared_ptr<std::vector<T>> p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
private:
    std::shared_ptr<std::vector<T>> check(size_t, const std::string&) const;

    std::weak_ptr<std::vector<T>> wptr;
    size_t curr;
};

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}


#endif
