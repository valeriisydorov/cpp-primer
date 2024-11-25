#include "Query.h"
#include "QueryBase.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "WordQuery.h"

// TODO remove it later
#include <iostream>


Query::Query(const std::string& s) : q(new WordQuery(s)) {
    // TODO remove the output later
    std::cout << "Query(const std::string& s)" << std::endl;
}

QueryResult Query::eval(const TextQuery& t) const {
    return q->eval(t);
}

std::string Query::rep() const {
    // TODO remove the output later
    std::cout << "Query::rep()" << std::endl;
    return q->rep();
}

std::ostream& operator<<(std::ostream& os, const Query& query) {
    return os << query.rep();
}
