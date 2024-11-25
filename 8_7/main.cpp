#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"

int main(int argc, char* argv[]) {
    char *ifn = argv[1];
    char *ofn = argv[2];

    std::ifstream ifst(ifn);
    std::ofstream ofst(ofn);

    if (!ifst.is_open()) {
        std::cerr << "Error opening an input file." << std::endl;
        return -1;
    }

    if (!ofst.is_open()) {
        std::cerr << "Error opening an output file." << std::endl;
        return -1;
    }

    Sales_data total;
    double price = 0;
    if (ifst >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (ifst >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                ofst << "Total: " << total.bookNo << " " << total.units_sold << " "
                          << total.revenue << " " << total.revenue / total.units_sold << "\n";
                total = trans;
            }
        }
        ofst << "Total: " << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << " " << total.revenue / total.units_sold << "\n";
    } else {
        std::cerr << "No data?" << std::endl;
    }

    return 0;
}