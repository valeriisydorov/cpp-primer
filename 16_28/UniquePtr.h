#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H


#include <cstddef>
#include <functional>
#include <utility>
#include "DebugDelete.h"


/**
 *
 * @tparam T
 * @tparam U
 */
template <typename T, typename U = DebugDelete> class UniquePtr {
public:
    UniquePtr() = default;
    explicit UniquePtr(T*);

    explicit UniquePtr(const UniquePtr<T, U>&) = delete;
    UniquePtr(UniquePtr<T, U>&&);
    UniquePtr& operator=(const UniquePtr<T>&) = delete;
    UniquePtr& operator=(UniquePtr<T, U>&&) noexcept;
    ~UniquePtr() noexcept;

    operator bool() const;
    T& operator*() const;
    T* operator->() const;

    T* get();
    void swap(UniquePtr<T, U>&);
    void reset();
    void reset(T*);
    T* release();
private:
    T* rawPtr = nullptr;
    U delFunc = U();
};

/**
 *
 * @tparam T
 * @tparam U
 * @param raw
 */
template <typename T, typename U> UniquePtr<T, U>::UniquePtr(T* raw) : rawPtr(raw){ }

/**
 *
 * @tparam T
 * @tparam U
 * @param other
 */
template <typename T, typename U> UniquePtr<T, U>::UniquePtr(UniquePtr<T, U>&& other) : rawPtr(other.rawPtr) {
    other.rawPtr = nullptr;
}

/**
 *
 * @tparam T
 * @tparam U
 * @param rhs
 * @return
 */
template <typename T, typename U> UniquePtr<T, U>& UniquePtr<T, U>::operator=(UniquePtr<T, U>&& rhs) noexcept {
    if (*this != rhs) {
        delFunc(rawPtr);
        rawPtr = nullptr;
        std::swap(*this, rhs);
    }
    return *this;
}

/**
 *
 * @tparam T
 * @tparam U
 */
template <typename T, typename U> UniquePtr<T, U>::~UniquePtr() noexcept {
    delFunc(rawPtr);
}

/**
 *
 * @tparam T
 * @tparam U
 * @return
 */
template <typename T, typename U> UniquePtr<T, U>::operator bool() const {
    return rawPtr != nullptr;
}

/**
 *
 * @tparam T
 * @tparam U
 * @return
 */
template <typename T, typename U> T& UniquePtr<T, U>::operator*() const {
    return *rawPtr;
}

/**
 *
 * @tparam T
 * @tparam U
 * @return
 */
template <typename T, typename U> T* UniquePtr<T, U>::operator->() const {
    return &*rawPtr;
}

/**
 *
 * @tparam T
 * @tparam U
 * @return
 */
template <typename T, typename U> T* UniquePtr<T, U>::get() {
    return rawPtr;
}

/**
 *
 * @tparam T
 * @tparam U
 * @param rhs
 */
template <typename T, typename U> inline void UniquePtr<T, U>::swap(UniquePtr<T, U>& rhs) {
    using std::swap;
    swap(rawPtr, rhs.rawPtr);
    swap(delFunc, rhs.delFunc);
}

/**
 *
 * @tparam T
 * @tparam U
 */
template <typename T, typename U> void UniquePtr<T, U>::reset() {
    delFunc(rawPtr);
    rawPtr = nullptr;
}

/**
 *
 * @tparam T
 * @tparam U
 * @param newPtr
 */
template <typename T, typename U> void UniquePtr<T, U>::reset(T* newPtr) {
    if (rawPtr != newPtr) {
        delFunc(rawPtr);
        rawPtr = newPtr;
    }
}

/**
 *
 * @tparam T
 * @tparam U
 * @return
 */
template <typename T, typename U> T* UniquePtr<T, U>::release() {
    T* retPtr = rawPtr;
    rawPtr = nullptr;
    return retPtr;
}


#endif
