#include <iostream>

template <typename T> void f(T) {
    std::cout << "f(T) \n";
}

template <typename T> void f(const T*) {
    std::cout << "f(const T*) \n";
}

template <typename T> void g(T) {
    std::cout << "g(T) \n";
}

template <typename T> void g(T*) {
    std::cout << "g(T*) \n";
}

int main() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    return 0;
}
