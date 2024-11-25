#include <iostream>
#include "Sales_data.h"
#include "CompareTemplate.h"


int main() {
    Sales_data data1{"0-201-78345-Х", 3, 20.0};
    Sales_data data2{"0-307-98754-Y", 5, 15.0};

    std::cout << compare(data1, data2) << std::endl;

    return 0;
}
