#include "Sales_data.h"
#include <set>

int main() {
    std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);

    return 0;
}
