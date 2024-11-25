#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data{"0-201-78345-Х", 3, 20.0};
    std::cout << data << std::endl;
//
//    Sales_data item;
//    if (std::cin >> item) {
//        std::cout << item << std::endl;
//    }

    return 0;
}