#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T> std::size_t vecCount(const std::vector<T>& vec, const T& n) {
    return std::count(vec.cbegin(), vec.cend(), n);
}

int main() {
    std::vector<int> iVec{1, 1, 2, 3, 5, 8, 5, 3, 2, 1, 1};
    std::cout << vecCount(iVec, 1) << '\n';

    std::vector<double> dVec{2.7, 3.14, 1.62, 3.14, 2.7, 2.7};
    std::cout << vecCount(dVec, 2.7) << '\n';

    std::vector<std::string> sVec{"Hi", "Hello", "Hey", "Hello", "Hi", "Hi", "Hey"};
    std::cout << vecCount(sVec, std::string("Hi")) << '\n';

    return 0;
}