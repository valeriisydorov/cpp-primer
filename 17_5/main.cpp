#include "FindAndReport.h"


int main()
{
    Sales_data trans11{"0-201-78345-Х", 3, 20.0};
    Sales_data trans12{"0-307-98754-W", 2, 12.0};
    Sales_data trans21{"0-201-78345-Х", 1, 20.0};
    Sales_data trans22{"0-307-98754-W", 4, 12.0};

    store store1({trans11, trans12});
    store store2({trans21, trans22});

    stores data({store1, store2});

    reportResult(std::cin, std::cout, data);


    return 0;
}
