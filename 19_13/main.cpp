#include <iostream>
#include "Sales_data.h"


int main()
{
    Sales_data TAOCP("0-201-03801-3");
    const std::string Sales_data::*pisbn = Sales_data::isbn_data();

    std::cout << TAOCP.*pisbn << std::endl;

    return 0;
}
