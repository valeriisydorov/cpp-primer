#include <iostream>

int main() {
    auto sum = [](int x, int y) -> int {
        return x + y;
    };

    std::cout << sum(3, 5) << std::endl;

    return 0;
}
