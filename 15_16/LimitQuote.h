#ifndef LIMITQUOTE_H
#define LIMITQUOTE_H

#include "DiscQuote.h"

class LimitQuote : public DiscQuote {
public:
    LimitQuote() = default;
    LimitQuote(const std::string&, double, std::size_t, double, std::size_t);

    double netPrice(std::size_t) const override;
    void debug(std::ostream&) const override;
private:
    std::size_t limit = 0;
};

#endif
