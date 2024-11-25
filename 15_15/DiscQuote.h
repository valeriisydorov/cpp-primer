#ifndef DISCQUOTE_H
#define DISCQUOTE_H

#include "Quote.h"

class DiscQuote : public Quote {
public:
    DiscQuote() = default;
    DiscQuote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }

    double netPrice(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

#endif
