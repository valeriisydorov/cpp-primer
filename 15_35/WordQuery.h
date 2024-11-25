#ifndef WORDQUERY_H
#define WORDQUERY_H


#include <string>
#include "QueryBase.h"

// TODO remove it later
#include <iostream>

class TextQuery;
class QueryResult;
class Query;

class WordQuery : public QueryBase {
    friend class Query;
    WordQuery(const std::string& s): queryWord(s) {
        // TODO remove the output later
        std::cout << "WordQuery(const std::string& s)" << std::endl;
    }
    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override;
    std::string queryWord;
};


#endif

