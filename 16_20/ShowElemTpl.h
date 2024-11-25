#ifndef SHOWELEMTPL_H
#define SHOWELEMTPL_H


#include <iostream>


template <template <typename> typename T, typename U> void showElem(const T<U>& c) {
    for (typename T<U>::const_iterator it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}


#endif
