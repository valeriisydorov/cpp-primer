#include "Quote.h"
#include "BulkQuote.h"
#include "Basket.h"
#include <vector>

int main() {
    Basket basket;
    BulkQuote item1("XXX-000-999", 20.0, 10, 0.1);
    BulkQuote item2("YYY-111-555", 15.0, 5, 0.2);

    basket.addItem(item1);
    basket.addItem(std::move(item2));

    basket.totalReceipt(std::cout);

    return 0;
}
