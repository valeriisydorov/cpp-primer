#ifndef BULKQUOTE_H
#define BULKQUOTE_H

#include "DiscQuote.h"

class BulkQuote : public DiscQuote {
public:
    BulkQuote() = default;
    BulkQuote(const std::string&, double, std::size_t, double);

    virtual double netPrice(std::size_t) const override;
    void debug(std::ostream&) const override;
};


#endif
