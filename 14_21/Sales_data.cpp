#include "Sales_data.h"

using std::istream;
using std::ostream;

inline double Sales_data::avgPrice() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

ostream& operator<<(ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avgPrice();
    return os;
}

istream& operator>>(istream& is, Sales_data& item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_data();
    }
    return is;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum;
    sum.bookNo = lhs.bookNo;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
    *this = *this + rhs;
    return *this;
}
