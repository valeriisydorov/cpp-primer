#include "Query.h"
#include "QueryBase.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "WordQuery.h"


Query::Query(const std::string& s) : q(new WordQuery(s)) { }

QueryResult Query::eval(const TextQuery& t) const {
    return q->eval(t);
}

std::string Query::rep() const {
    return q->rep();
}

std::ostream& operator<<(std::ostream& os, const Query& query) {
    return os << query.rep();
}
