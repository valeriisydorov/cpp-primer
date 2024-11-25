#ifndef BASKET_H
#define BASKET_H

#include "Quote.h"
#include <memory>
#include <set>

class Basket {
public:
    void addItem(const Quote&);
    void addItem(Quote&&);
    double totalReceipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, bool (*)(const std::shared_ptr<Quote>&, const std::shared_ptr<Quote>&)> items{compare};
};


#endif