#include <iostream>
#include <string>

template <typename T> std::ostream& print(std::ostream& os, const T& t) {
    return os << t;
}

template <typename T, typename ... Args> std::ostream& print(std::ostream& os, const T& t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest ...);
}

int main() {
    int i = 13;
    double d = 2.7;
    std::string s = "Hello";

    print(std::cout, d, i, s, 42);

    return 0;
}
