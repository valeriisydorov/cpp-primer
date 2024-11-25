#include "BulkQuote.h"

BulkQuote::BulkQuote(const std::string& book, double price, std::size_t qty, double disc) : DiscQuote(book, price, qty, disc) { }

double BulkQuote::netPrice(std::size_t cnt) const {
    if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

void BulkQuote::debug(std::ostream& os) const {
    os << "bookNo: " << isbn() << "\n" << "price: " << price << "\n"
        << "minQty: " << quantity << "\n" << "discount: " << discount << "\n";
}