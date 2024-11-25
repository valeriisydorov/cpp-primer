#ifndef BULKQUOTE_H
#define BULKQUOTE_H

#include "Quote.h"

class BulkQuote : public Quote {
public:
    BulkQuote() = default;
    BulkQuote(const std::string&, double, std::size_t, double);

    BulkQuote(const BulkQuote&);
    BulkQuote& operator=(const BulkQuote&);
    BulkQuote(BulkQuote&&) = default;
    BulkQuote& operator=(BulkQuote&&) = default;

    virtual double netPrice(std::size_t) const override;
    void debug(std::ostream&) const override;
private:
    std::size_t quantity = 0;
    double discount = 0.0;
};


#endif
