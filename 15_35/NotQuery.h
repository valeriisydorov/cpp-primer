#ifndef NOTQUERY_H
#define NOTQUERY_H


#include "QueryBase.h"
#include "Query.h"

// TODO remove it later
#include <iostream>

class NotQuery : public QueryBase {
    friend Query operator~(const Query&);
    NotQuery(const Query& q): query(q) {
        // TODO remove the output later
        std::cout << "NotQuery(const Query& q)" << std::endl;
    }
    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override;
    Query query;
};

#endif
