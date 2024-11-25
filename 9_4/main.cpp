#include <iostream>
#include "SearchNumber.h"

int main() {
    std::vector<int> range{1, 1, 2, 3, 5, 8, 13, 21, 34};
    int number = 8;

    if (searchNumber(range.begin(), range.end(), number)) {
        std::cout << "The number " << number << " is on the range" << std::endl;
    } else {
        std::cout << "The number " << number << " isn't on the range" << std::endl;
    }

    return 0;
}
