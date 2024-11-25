#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream&);
    QueryResult getResult(std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> srcFile;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> wordsMap;
};

#endif
