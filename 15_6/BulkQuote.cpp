#include "BulkQuote.h"

BulkQuote::BulkQuote(const std::string& book, double p, std::size_t qty, double disc) : Quote(book, p), minQty(qty), discount(disc) { }

double BulkQuote::netPrice(std::size_t cnt) const {
    if (cnt >= minQty) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}