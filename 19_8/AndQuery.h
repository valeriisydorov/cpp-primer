#ifndef ANDQUERY_H
#define ANDQUERY_H


#include "BinaryQuery.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);

    QueryResult eval(const TextQuery&) const;

public:
    AndQuery(const Query& left, const Query& right): BinaryQuery(left, right, "&") { }
};


#endif
