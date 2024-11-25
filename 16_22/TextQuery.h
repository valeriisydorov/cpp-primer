#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "QueryResult.h"

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> wm;
};

#endif
