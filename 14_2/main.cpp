#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data1{"0-201-78345-Х", 3, 20.0};
    Sales_data data2;
    Sales_data data3{"0-201-78345-Х"};
    if (std::cin) {
        Sales_data data4{std::cin};
    }
    return 0;
}