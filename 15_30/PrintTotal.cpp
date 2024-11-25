#include "PrintTotal.h"

double printTotal(std::ostream& os, const Quote& item, size_t n) {
    double ret = item.netPrice(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}