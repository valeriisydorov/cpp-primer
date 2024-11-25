#ifndef BEGINENDTEMPLATE_H
#define BEGINENDTEMPLATE_H


template <typename T, unsigned U> T* beginTpl(T (&arr)[U]) {
    return arr;
}

template <typename T, unsigned U> T* endTpl(T (&arr)[U]) {
    return arr + U;
}


#endif
