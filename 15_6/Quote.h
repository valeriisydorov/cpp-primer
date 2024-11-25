#ifndef QUOTE_H
#define QUOTE_H


#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book, double salesPrice): bookNo(book), price(salesPrice) { }
    std::string isbn() const;
    virtual double netPrice(std::size_t) const;
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};


#endif
