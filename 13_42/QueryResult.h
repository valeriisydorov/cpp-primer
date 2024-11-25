#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <set>
#include "StrVec.h"

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<std::vector<std::string>::size_type>>p, std::shared_ptr<StrVec> f): sought(s), lines(p), file(f) {}
private:
    std::string sought;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> lines;
    std::shared_ptr<StrVec> file;
};

#endif
