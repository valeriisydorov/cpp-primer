#include <iostream>
using std::istream;
using std::ostream;

#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    double revenue = 0;
    if (item.units_sold != 0) {
        revenue = item.revenue / item.units_sold;
    }
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}