#ifndef DISCOUNTQUOTE_H
#define DISCOUNTQUOTE_H

#include "BulkQuote.h"

class DiscountQuote : public BulkQuote {
public:
    DiscountQuote() = default;
    DiscountQuote(const std::string&, double, std::size_t, double, std::size_t);

    double netPrice(std::size_t) const override;
    void debug(std::ostream&) const override;
private:
    std::size_t limit = 0;
};


#endif
