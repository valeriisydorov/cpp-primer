#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data{"0-201-78345-Х", 3, 20.0};
    std::cout << data << std::endl;

    return 0;
}