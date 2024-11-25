#include "Sales_data.h"


#include <iostream>


using std::istream;
using std::ostream;

inline double Sales_data::avg_price() const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);

    return sum;
}

ostream& operator<<(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

    return os;
}

istream& operator>>(istream& is, Sales_data& item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_data();
    }

    return is;
}

bool compareIsbn(const Sales_data& trans1, const Sales_data& trans2)
{
    return trans1.isbn() < trans2.isbn();
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum;
    sum.bookNo = lhs.bookNo;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;

    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    if (isbn() != rhs.isbn())
    {
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    }
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}
