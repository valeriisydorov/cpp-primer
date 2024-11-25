#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v{2, 5, 10, 0, 45, 0, 99, 3, 24};
    std::vector<int>::reverse_iterator lastZero = std::find(v.rbegin(), v.rend(),0);
    std::cout << *lastZero << std::endl;
    std::cout << *(--lastZero) << std::endl;

    return 0;
}
