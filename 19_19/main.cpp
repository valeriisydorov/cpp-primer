#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include "Sales_data.h"


Sales_data getFirstAverageElement(std::vector<Sales_data> vec, double priceVal)
{
    auto it = std::find_if(vec.begin(), vec.end(),[&priceVal](const Sales_data &item)
    {
        return std::mem_fn(item.get_avg_price())(item) > priceVal;
    });

    return *it;
}


int main()
{
    Sales_data CLRS("978-0-262-04630-5", 1, 49.99);
    Sales_data SICP("978-0262510875", 1, 99.99);
    Sales_data TAOCP("0-201-03801-3", 1, 199.99);

    std::vector<Sales_data> vec{CLRS, SICP, TAOCP};

    Sales_data book = getFirstAverageElement(vec, 49.99);
    auto isbn = book.isbn_data();

    std::cout << book.*isbn << std::endl;

    return 0;
}
