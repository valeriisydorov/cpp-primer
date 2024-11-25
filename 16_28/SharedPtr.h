#ifndef SHAREDPTR_H
#define SHAREDPTR_H


#include <cstddef>
#include <functional>
#include <utility>


/**
 *
 * @tparam T
 */
template <typename T> class SharedPtr {
public:
    SharedPtr() noexcept;
    explicit SharedPtr(T*);
    explicit SharedPtr(T*, std::function<void(T*)> delFunc = nullptr);

    explicit SharedPtr(const SharedPtr<T>&);
    SharedPtr(SharedPtr<T>&&);
    SharedPtr& operator=(const SharedPtr<T>&) noexcept;
    SharedPtr& operator=(SharedPtr<T>&&) noexcept;
    ~SharedPtr() noexcept;

    operator bool() const;
    T& operator*() const;
    T* operator->() const;

    T* get();
    std::size_t used();
    bool unique();
    void swap(SharedPtr<T>&);
    void reset();
    void reset(T*);
    void reset(T*, std::function<void(T*)>);
private:
    T* rawPtr = nullptr;
    std::size_t* refCount = nullptr;
    std::function<void(T*)> delFunc = nullptr;

    void fullReset();
};

/**
 *
 * @tparam T
 */
template <typename T> SharedPtr<T>::SharedPtr() noexcept : refCount(new std::size_t(1)) { }

/**
 *
 * @tparam T
 * @param raw
 */
template <typename T> SharedPtr<T>::SharedPtr(T* raw) : rawPtr(raw), refCount(new std::size_t(1)) { }

/**
 *
 * @tparam T
 * @param raw
 * @param del
 */
template <typename T> SharedPtr<T>::SharedPtr(T* raw, std::function<void(T*)> del) : rawPtr(raw), refCount(new std::size_t(1), delFunc(del)) { }

/**
 *
 * @tparam T
 * @param other
 */
template <typename T> SharedPtr<T>::SharedPtr(const SharedPtr<T>& other) : rawPtr(other.rawPtr), refCount(other.refCount), delFunc(other.delFunc) {
    ++*refCount;
}

/**
 *
 * @tparam T
 * @param other
 */
template <typename T> SharedPtr<T>::SharedPtr(SharedPtr<T>&& other) : rawPtr(other.rawPtr), refCount(other.refCount), delFunc(std::move(other.delFunc)) {
    other.rawPtr = nullptr;
    other.refCount = nullptr;
}

/**
 *
 * @tparam T
 * @param rhs
 * @return
 */
template <typename T> SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& rhs) noexcept {
    if (*this != rhs) {
        ++*rhs.refCount;
        fullReset();
        rawPtr = rhs.rawPtr;
        refCount = rhs.refCount;
        delFunc = rhs.delFunc;
    }
    return *this;
}

/**
 *
 * @tparam T
 * @param rhs
 * @return
 */
template <typename T> SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& rhs) noexcept {
    if (*this != rhs) {
        fullReset();
        SharedPtr<T>(std::move(rhs)).swap(*this);
    }
    return *this;
}

/**
 *
 * @tparam T
 */
template <typename T> SharedPtr<T>::~SharedPtr() noexcept {
    fullReset();
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T> SharedPtr<T>::operator bool() const {
    return rawPtr != nullptr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T> T& SharedPtr<T>::operator*() const {
    return *rawPtr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T> T* SharedPtr<T>::operator->() const {
    return &*rawPtr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T> T* SharedPtr<T>::get() {
    return rawPtr;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T> std::size_t SharedPtr<T>::used() {
    return *refCount;
}

/**
 *
 * @tparam T
 * @return
 */
template <typename T> bool SharedPtr<T>::unique() {
    return 1 == *refCount;
}

/**
 *
 * @tparam T
 * @param rhs
 */
template <typename T> inline void SharedPtr<T>::swap(SharedPtr<T>& rhs) {
    using std::swap;
    swap(rawPtr, rhs.rawPtr);
    swap(refCount, rhs.refCount);
    swap(delFunc, rhs.delFunc);
}

/**
 *
 * @tparam T
 */
template <typename T> void SharedPtr<T>::reset() {
    fullReset();
}

/**
 *
 * @tparam T
 * @param newPtr
 */
template <typename T> void SharedPtr<T>::reset(T* newPtr) {
    if (rawPtr != newPtr) {
        fullReset();
        rawPtr = newPtr;
        refCount = new std::size_t(1);
    }
}

/**
 *
 * @tparam T
 * @param newPtr
 * @param del
 */
template <typename T> void SharedPtr<T>::reset(T* newPtr,  std::function<void(T*)> del) {
    reset(newPtr);
    delFunc = std::move(del);
}

/**
 *
 * @tparam T
 */
template <typename T> inline void SharedPtr<T>::fullReset() {
    if (--*refCount == 0) {
        (delFunc) ? delFunc(rawPtr) : delete rawPtr;
        delete refCount;
    }
    rawPtr = nullptr;
    refCount = nullptr;
}


#endif
