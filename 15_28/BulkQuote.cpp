#include "BulkQuote.h"

BulkQuote::BulkQuote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc)  { }

BulkQuote::BulkQuote(const BulkQuote& other) : Quote(other), quantity(other.quantity), discount(other.discount) { }

BulkQuote& BulkQuote::operator=(const BulkQuote& other) {
    if (this != &other) {
        Quote::operator=(other);
        quantity = other.quantity;
        discount = other.discount;
    }
    return *this;
}

double BulkQuote::netPrice(std::size_t cnt) const {
    if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

void BulkQuote::debug(std::ostream& os) const {
    os << "bookNo: " << isbn() << "\n" << "price: " << price << "\n"
        << "quantity: " << quantity << "\n" << "discount: " << discount << "\n";
}