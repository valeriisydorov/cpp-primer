#ifndef QUERYBASE_H
#define QUERYBASE_H


#include <string>

class TextQuery;
class QueryResult;

class QueryBase {
    friend class Query;
protected:
    virtual ~QueryBase() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};


#endif
