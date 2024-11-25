#ifndef ANDQUERY_H
#define ANDQUERY_H


#include "BinaryQuery.h"

// TODO remove it later
#include <iostream>

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right): BinaryQuery(left, right, "&") {
        // TODO remove the output later
        std::cout << "AndQuery(const Query& left, const Query& right)" << std::endl;
    }
    QueryResult eval(const TextQuery&) const;
};


#endif
