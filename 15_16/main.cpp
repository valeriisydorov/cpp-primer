#include "Quote.h"
#include "BulkQuote.h"
#include "LimitQuote.h"
#include "PrintTotal.h"

int main() {
    Quote item1("XXX-999-333", 20.0);
    BulkQuote item2("XXX-000-555", 15.0, 5, 0.2);
    LimitQuote item3("XXX-777-111", 10.0, 10, 0.3, 5);

    printTotal(std::cout, item1, 10);
    printTotal(std::cout, item2, 5);
    printTotal(std::cout, item3, 50);

//    DiscQuote item("XXX-999-333", 20.0);

    return 0;
}
