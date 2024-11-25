#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
    Sales_data(std::string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt * price) { }
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(std::string s): Sales_data(s, 0, 0) { }
    Sales_data(std::istream &is): Sales_data() { is >> *this; };
    Sales_data& operator+=(const Sales_data&);
    std::string isbn() const { return bookNo; }
    inline double avgPrice() const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif
