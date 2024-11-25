#ifndef PRINTTEMPLATE_H
#define PRINTTEMPLATE_H


#include <iostream>

template <typename T, unsigned U> void printTpl(const T (&arr)[U]) {
    for (T el: arr) {
        std::cout << el << std::endl;
    }
}


#endif
