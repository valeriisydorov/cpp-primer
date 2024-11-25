#include "OrQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"

Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

// TODO: This is a stub definition. Remove the default constructor from QueryResult after this definition implementation
QueryResult OrQuery::eval(const TextQuery& text) const {
    QueryResult stub;
    return stub;
}