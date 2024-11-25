#include "LimitQuote.h"

LimitQuote::LimitQuote(const std::string& book, double price, std::size_t qty, double disc, std::size_t lim) : DiscQuote(book, price, qty, disc), limit(lim) { }

double LimitQuote::netPrice(std::size_t cnt) const {
    if (cnt >= quantity) {
        if (cnt <= limit) {
            return cnt * (1 - discount) * price;
        } else {
            return limit * (1 - discount) * price + (cnt - limit) * price;
        }
    } else {
        return cnt * price;
    }
}

void LimitQuote::debug(std::ostream& os) const {
    os << "bookNo: " << isbn() << "\n" << "price: " << price << "\n"
       << "quantity: " << quantity << "\n" << "discount: " << discount << "\n"
       << "limit: " << limit << "\n";
}