#include "Basket.h"
#include "PrintTotal.h"

void Basket::addItem(const Quote& sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basket::addItem(Quote&& sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}

double Basket::totalReceipt(std::ostream& os) const {
    double sum = 0.0;
    for (std::multiset<std::shared_ptr<Quote>, bool (*)(const std::shared_ptr<Quote>&, const std::shared_ptr<Quote>&)>::iterator iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)) {
        sum += printTotal(os, **iter, items.count(*iter));
    }

    os << "Total Sale: " << sum << std::endl;
    return sum;
}
