#ifndef NOTQUERY_H
#define NOTQUERY_H


#include "QueryBase.h"
#include "Query.h"

class NotQuery : public QueryBase {
    friend Query operator~(const Query&);
    NotQuery(const Query& q): query(q) { }
    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override;
    Query query;
};

#endif
