#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data item1;
    Sales_data item2{"0-201-78345-Х"};
    Sales_data item3{"0-201-78345-Х", 3,  20.00};

    print(std::cout, item1) << std::endl;
    print(std::cout, item2) << std::endl;
    print(std::cout, item3) << std::endl;

    if (std::cin) {
        Sales_data item4{std::cin};
        print(std::cout, item4) << std::endl;
    }

    return 0;
}