#ifndef QUERY_H
#define QUERY_H


#include <memory>
#include <string>

class TextQuery;
class QueryResult;
class QueryBase;

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
    friend std::ostream& operator<<(std::ostream& os, const Query& query);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery&) const;
    std::string rep() const;
private:
    Query(std::shared_ptr<QueryBase> query): q(query) { }
    std::shared_ptr<QueryBase> q;
};


#endif
