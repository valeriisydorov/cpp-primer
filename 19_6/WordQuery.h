#ifndef WORDQUERY_H
#define WORDQUERY_H


#include <string>
#include "QueryBase.h"

class TextQuery;
class QueryResult;
class Query;

class WordQuery : public QueryBase {
    friend class Query;
    WordQuery(const std::string& s): queryWord(s) {}
    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override;
    std::string queryWord;
};


#endif

