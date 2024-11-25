#include "Sales_data.h"
#include <set>

int main() {
    // std::multiset<Sales_data, decltype(compareIsbn)&> bookstore(compareIsbn);
    std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
    std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)>::const_iterator it = bookstore.begin();

    return 0;
}
