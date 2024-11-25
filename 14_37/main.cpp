#include <iostream>
#include <vector>
#include <algorithm>

#include "IsEqual.h"

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};
    int oldVal = 3;
    int newVal = 13;

    IsEqual isEqual;
    std::replace_if(numbers.begin(), numbers.end(), std::bind(isEqual, std::placeholders::_1, oldVal), newVal);

    std::cout << "Updated sequence: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
