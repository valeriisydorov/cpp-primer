#ifndef SUMTPL_H
#define SUMTPL_H

template <typename T> auto sum(T a, T b) -> decltype(a + b) {
    return a + b;
}

#endif
