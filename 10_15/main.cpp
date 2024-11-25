#include <iostream>

int main() {
    int x = 3;
    auto sum = [x](int y) -> int {
        return x + y;
    };

    std::cout << sum(5) << std::endl;

    return 0;
}
