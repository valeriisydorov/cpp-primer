#ifndef ORQUERY_H
#define ORQUERY_H


#include "BinaryQuery.h"

// TODO remove it later
#include <iostream>

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right): BinaryQuery(left, right, "|") {
        // TODO remove the output later
        std::cout << "OrQuery(const Query& left, const Query& right)" << std::endl;
    }
    QueryResult eval(const TextQuery&) const;
};


#endif
