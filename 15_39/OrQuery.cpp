#include "OrQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"


Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const {
    QueryResult left = lhs.eval(text);
    QueryResult right = rhs.eval(text);
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> retLines = std::make_shared<std::set<std::vector<std::string>::size_type>>(left.begin(), left.end());
    retLines->insert(right.begin(), right.end());
    return QueryResult(rep(), retLines, left.getFile());
}