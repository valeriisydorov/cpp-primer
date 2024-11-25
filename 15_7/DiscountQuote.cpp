#include "DiscountQuote.h"

DiscountQuote::DiscountQuote(const std::string& book, double p, std::size_t qty, double disc, std::size_t lim) : BulkQuote(book, p, qty, disc), limit(lim) { }

double DiscountQuote::netPrice(std::size_t cnt) const {
    if (cnt >= minQty) {
        if (cnt <= limit) {
            return cnt * (1 - discount) * price;
        } else {
            return limit * (1 - discount) * price + (cnt - limit) * price;
        }
    } else {
        return cnt * price;
    }
}