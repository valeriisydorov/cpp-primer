#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <memory>

class QueryResult {
    friend std::ostream& print(std::ostream&, QueryResult&);
public:
    QueryResult(std::string sw,
                std::shared_ptr<std::set<std::vector<std::string>::size_type>> lines,
                std::shared_ptr<std::vector<std::string>> file):
                searchWord(sw), lineNumbers(lines), srcFile(file) {}
private:
    std::string searchWord;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> lineNumbers;
    std::shared_ptr<std::vector<std::string>> srcFile;
};

#endif