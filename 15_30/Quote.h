#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book, double salesPrice): bookNo(book), price(salesPrice) { }
    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote&&) = default;
    virtual ~Quote() = default;

    virtual Quote* clone() const &;
    virtual Quote* clone() &&;

    std::string isbn() const;
    virtual double netPrice(std::size_t) const;
    virtual void debug(std::ostream&) const;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};


#endif
