#include "Quote.h"
#include "BulkQuote.h"
#include "PrintTotal.h"
#include <vector>

int main() {
    std::vector<Quote> basket;
    BulkQuote item1("XXX-000-999", 20.0, 10, 0.1);
    BulkQuote item2("YYY-111-555", 15.0, 5, 0.2);

    printTotal(std::cout, item1, 10);
    printTotal(std::cout, item2, 5);

    basket.push_back(item1);
    basket.push_back(item2);

    double totalNetPrice = 0.0;
    for (std::vector<Quote>::iterator it = basket.begin(); it != basket.end(); ++it) {
        totalNetPrice += (*it).netPrice(15);
    }

    std::cout << "Total net price: " << totalNetPrice << std::endl;

    return 0;
}
