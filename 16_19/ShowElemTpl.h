#ifndef SHOWELEMTPL_H
#define SHOWELEMTPL_H


#include <iostream>


template <template <typename> typename T, typename U> void showElem(const T<U>& c) {
    for (typename T<U>::size_type i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
}


#endif
