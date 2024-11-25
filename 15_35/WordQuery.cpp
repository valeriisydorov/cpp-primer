#include "WordQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"

QueryResult WordQuery::eval(const TextQuery& t) const {
    return t.query(queryWord);
}

std::string WordQuery::rep() const {
    // TODO remove the output later
    std::cout << "WordQuery::rep()" << std::endl;
    return queryWord;
}