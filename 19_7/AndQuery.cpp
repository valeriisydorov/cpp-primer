#include "AndQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <algorithm>


Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery& text) const {
    QueryResult left = lhs.eval(text);
    QueryResult right = rhs.eval(text);
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> retLines = std::make_shared<std::set<std::vector<std::string>::size_type>>();
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*retLines, retLines->begin()));
    return QueryResult(rep(), retLines, left.getFile());
}