#ifndef BINARYQUERY_H
#define BINARYQUERY_H


#include "QueryBase.h"
#include "Query.h"
#include <string>

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s): lhs(l), rhs(r), opSymbol(s) { }
    std::string rep() const;
    Query lhs, rhs;
    std::string opSymbol;
};


#endif
