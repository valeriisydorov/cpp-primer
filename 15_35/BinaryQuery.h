#ifndef BINARYQUERY_H
#define BINARYQUERY_H


#include "QueryBase.h"
#include "Query.h"
#include <string>

// TODO remove it later
#include <iostream>

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s): lhs(l), rhs(r), opSymbol(s) {
        // TODO remove the output later
        std::cout << "BinaryQuery(const Query& l, const Query& r, std::string s)" << std::endl;
    }
    std::string rep() const;
    Query lhs, rhs;
    std::string opSymbol;
};


#endif
