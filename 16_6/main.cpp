#include <iostream>
#include "BeginEndTemplate.h"

int main() {
    int arr[] = {1, 2, 3, 5, 7};

    int* beg = beginTpl(arr);
    int* end = endTpl(arr);

    for (int* it = beg; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
