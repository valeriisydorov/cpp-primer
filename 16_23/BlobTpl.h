#ifndef BLOBTPL_H
#define BLOBTPL_H


#include <memory>
#include <initializer_list>
#include <vector>
#include <string>

template <typename T> class Blob;
template <typename T> class BlobPtr;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);
    template<typename It> Blob(It b, It e);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }
    void push_back(const T&& t) { data->push_back(std::move(t)); }
    void pop_back();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;
private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_type i, const std::string& msg) const;
};

template <typename T> Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T> Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) { }

template <typename T> template <typename It> Blob<T>::Blob(It b, It e): data(std::make_shared<std::vector<T>>(b, e)) { }

template <typename T> void Blob<T>::check(size_type i, const std::string& msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

template <typename T> T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T> bool operator==(const Blob<T> lhs, const Blob<T> rhs) {
    if (rhs.size() != lhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}



#endif
