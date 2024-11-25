#include <iostream>
#include <chrono>

#include "HasPtr.h"

int main() {
    const int iterations = 1000000;

    HasPtr obj1("Hello");
    HasPtr obj2("World");
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        obj2 = obj1;
    }
    auto end = std::chrono::steady_clock::now();
    std::cout << "HasPtr& operator=(const HasPtr&): "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

//    HasPtr obj1("Hello");
//    HasPtr obj2("World");
//    auto start = std::chrono::steady_clock::now();
//    for (int i = 0; i < iterations; ++i) {
//        obj2 = std::move(obj1);
//    }
//    auto end = std::chrono::steady_clock::now();
//    std::cout << "HasPtr& operator=(HasPtr): "
//              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
//              << " ms" << std::endl;

    return 0;
}
