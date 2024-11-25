#include <iostream>
#include "Sales_data.h"

int main() {
    if (std::cin) {
        Sales_data total{std::cin};
        while (std::cin) {
            Sales_data trans{std::cin};
            if (total.isbn() == trans.isbn()) {
                total = add(total, trans);
            } else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data?" << std::endl;
    }

    return 0;
}