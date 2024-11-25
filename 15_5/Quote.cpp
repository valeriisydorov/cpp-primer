#include "Quote.h"

std::string Quote::isbn() const {
    return bookNo;
}

double Quote::netPrice(std::size_t n) const {
    return n * price;
}
