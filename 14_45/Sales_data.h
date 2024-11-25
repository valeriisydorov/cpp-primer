#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Sales_data {
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend istream& operator>>(istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
    Sales_data(string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt * price) { }
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(string s): Sales_data(s, 0, 0) { }
    Sales_data(istream& is): Sales_data() { is >> *this; };
    Sales_data& operator=(const string&);
    Sales_data& operator+=(const Sales_data&);
    operator double() const;
    operator string() const;
    string isbn() const { return bookNo; }
    inline double avgPrice() const;
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif
