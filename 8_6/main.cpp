#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"

int main(int argc, char* argv[]) {
    char *fn = argv[1];

    std::ifstream fst(fn);

    if (!fst.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return -1;
    }

    Sales_data total;
    double price = 0;
    if (fst >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (fst >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << "Total: " << total.bookNo << " " << total.units_sold << " "
                          << total.revenue << " " << total.revenue / total.units_sold << std::endl;
                total = trans;
            }
        }
        std::cout << "Total: " << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << " " << total.revenue / total.units_sold << std::endl;
    } else {
        std::cerr << "No data?" << std::endl;
    }

    return 0;
}