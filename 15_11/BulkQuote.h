#ifndef BULKQUOTE_H
#define BULKQUOTE_H

#include "Quote.h"

class BulkQuote : public Quote {
public:
    BulkQuote() = default;
    BulkQuote(const std::string&, double, std::size_t, double);

    virtual double netPrice(std::size_t) const override;
    void debug(std::ostream&) const override;
protected:
    std::size_t minQty = 0;
    double discount = 0.0;
};


#endif