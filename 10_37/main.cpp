#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> fib{0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    std::vector<int> range;
    std::copy(fib.rbegin() + 3, fib.rbegin() + 7, std::back_inserter(range));

    std::for_each(range.begin(), range.end(), [] (int i) -> void {
        std::cout << i << " ";
    });
    std::cout << std::endl;

    return 0;
}
