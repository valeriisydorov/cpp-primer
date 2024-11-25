#include <iostream>
#include "Sales_data.h"


int main()
{
    Sales_data TAOCP("0-201-03801-3", 1, 199.99);
    Sales_data CLRS("978-0-262-04630-5", 1, 49.99);

    auto total = TAOCP + CLRS;
    auto avg = total.get_avg_price();

    std::cout << (total.*avg)() << std::endl;

    return 0;
}
