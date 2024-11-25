#include "NotQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"


std::string NotQuery::rep() const {
    // TODO remove the output later
    std::cout << "NotQuery::rep()" << std::endl;
    return "~(" + query.rep() + ")";
}

Query operator~(const Query& operand) {
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

// TODO: This is a stub definition. Remove the default constructor from QueryResult after this definition implementation
QueryResult NotQuery::eval(const TextQuery& text) const {
    QueryResult stub;
    return stub;
}