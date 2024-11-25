#include "Quote.h"
#include "BulkQuote.h"
#include "PrintTotal.h"

int main() {
    Quote item1("XXX-999-333", 20.0);
    BulkQuote item2("XXX-000-555", 15.0, 5, 0.2);

    printTotal(std::cout, item1, 10);
    printTotal(std::cout, item2, 5);

    return 0;
}
