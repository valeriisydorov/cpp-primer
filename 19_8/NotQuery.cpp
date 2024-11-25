#include "NotQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"


std::string NotQuery::rep() const {
    return "~(" + query.rep() + ")";
}

Query operator~(const Query& operand) {
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery& text) const {
    QueryResult result = query.eval(text);
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> retLines = std::make_shared<std::set<std::vector<std::string>::size_type>>();
    auto beg = result.begin();
    auto end = result.end();
    size_t size = result.getFile()->size();
    for (size_t n = 0; n != size; ++n) {
        if (beg == end || *beg != n) {
            retLines->insert(n);
        } else if (beg != end) {
            ++beg;
        }
    }
    return QueryResult(rep(), retLines, result.getFile());
}