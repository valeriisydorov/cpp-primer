#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total = add(total, trans);
            } else {
                print(std::cout, total);
                std::cout << std::endl;
                total = trans;
            }
        }
        print(std::cout, total);
        std::cout << std::endl;
    } else {
        std::cerr << "No data?" << std::endl;
    }

    return 0;
}