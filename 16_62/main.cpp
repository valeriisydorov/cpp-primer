#include <iostream>
#include <unordered_set>
#include "Sales_data.h"

namespace std {
    template<> struct hash<Sales_data> {
        using result = size_t;
        using argument_type = Sales_data;
        size_t operator()(const Sales_data&) const;
    };
    size_t hash<Sales_data>::operator()(const Sales_data& s) const {
        return hash<std::string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
}

int main() {
    Sales_data data1{"0-201-78345-Х", 3, 20.0};
    Sales_data data2{"0-307-98754-Y", 5, 15.0};
    std::unordered_multiset<Sales_data> dataSet;

    dataSet.insert(data1);
    dataSet.insert(data2);

    for (const auto &item: dataSet) {
        std::cout << item << "\n";
    }

    return 0;
}