#include <iostream>
#include <string>

template <typename T, typename ... Args> void foo(const T& t, const Args& ... rest) {
    std::cout << sizeof ... (Args) << std::endl;
    std::cout << sizeof ... (rest) << std::endl;
}

int main() {
    int i = 0;
    double d = 3.14;
    std::string s = "Hello";

    return 0;
}
