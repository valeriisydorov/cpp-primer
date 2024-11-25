#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);

    friend std::istream& operator>>(std::istream&, const Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend Sales_data& operator+=(Sales_data&, const Sales_data&);
public:
    Sales_data(std::string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt * price) {
        std::cout << "Constructor1" << std::endl;
    }
    Sales_data(): Sales_data("", 0, 0) {
        std::cout << "Constructor2" << std::endl;
    };
    Sales_data(std::string s): Sales_data(s, 0, 0) {
        std::cout << "Constructor3" << std::endl;
    };
    Sales_data(std::istream &is): Sales_data() {
        read(is, *this);
        std::cout << "Constructor4" << std::endl;
    };

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    inline double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

inline double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

#endif
