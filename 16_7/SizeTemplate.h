#ifndef SIZETEMPLATE_H
#define SIZETEMPLATE_H


template <typename T, size_t U> constexpr size_t sizeTpl(T (&arr)[U]) {
    return U;
}


#endif SIZETEMPLATE_H
