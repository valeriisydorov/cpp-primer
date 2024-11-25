#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

int main() {
    std::ifstream ifst("../data.txt");
    std::ofstream ofst("../result.txt");

    if (!ifst.is_open()) {
        std::cerr << "Error opening an input file." << std::endl;
        return -1;
    }

    if (!ofst.is_open()) {
        std::cerr << "Error opening an output file." << std::endl;
        return -1;
    }

    std::vector<Sales_data> total;
    Sales_data trans;
    double price = 0;
    while (ifst >> trans.bookNo >> trans.units_sold >> price) {
        trans.revenue = trans.units_sold * price;
        total.push_back(trans);
    }

    std::sort(total.begin(), total.end(), [](Sales_data& trans1, Sales_data& trans2) -> bool {
        return trans1.bookNo < trans2.bookNo;
    });

    for (Sales_data& tr: total) {
        ofst << tr.bookNo << "\n";
    }

    return 0;
}