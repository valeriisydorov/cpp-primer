#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book, double salesPrice): bookNo(book), price(salesPrice) { }
    virtual ~Quote() = default;
    std::string isbn() const;
    virtual double netPrice(std::size_t) const;
    virtual void debug(std::ostream&) const;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};


#endif
