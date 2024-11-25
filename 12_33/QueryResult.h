#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <set>

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<std::vector<std::string>::size_type>>p, std::shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) {}

    std::set<std::vector<std::string>::size_type>::const_iterator begin() const {
        return lines->cbegin();
    }
    std::set<std::vector<std::string>::size_type>::const_iterator end() const {
        return lines->cend();
    }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif
