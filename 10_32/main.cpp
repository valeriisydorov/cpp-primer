#include "Sales_item.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

bool compareBookNo(Sales_item& trans1, Sales_item& trans2) {
    return trans1.isbn() < trans2.isbn();
}

int main() {
    std::ifstream ifs("../book_sales");
//    std::istream_iterator<Sales_item> in(std::cin), eof;
    std::istream_iterator<Sales_item> in(ifs), eof;
    std::ostream_iterator<Sales_item> out(std::cout, "\n");
    std::vector<Sales_item> trans(in, eof), total;
    std::sort(trans.begin(), trans.end(), compareBookNo);
    std::vector<Sales_item>::iterator it = trans.begin();

    Sales_item sum = *it++;
    while (it != trans.end()) {
        if (sum.isbn() == (*it).isbn()) {
            sum += *it;
        } else {
            total.push_back(sum);
            sum = *it;
        }
        it++;
    }
    total.push_back(sum);

    std::for_each(total.begin(), total.end(), [&out] (Sales_item& item) -> void {
        out = item;
    });

    return 0;
}
