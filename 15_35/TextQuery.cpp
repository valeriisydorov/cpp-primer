#include "QueryResult.h"
#include "TextQuery.h"


#include <sstream>
#include <utility>

// TODO remove it later
#include <iostream>

TextQuery::TextQuery(std::ifstream& is): file(new std::vector<std::string>) {
    std::string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;

        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            std::shared_ptr<std::set<std::vector<std::string>::size_type>>& lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<std::vector<std::string>::size_type>);
            }
            lines->insert(n);
        }
    }

    // TODO remove the output later
    std::cout << "TextQuery(std::ifstream& is)" << std::endl;
}

QueryResult TextQuery::query(const std::string& sought) const {
    static std::shared_ptr<std::set<std::vector<std::string>::size_type>> nodata(new std::set<std::vector<std::string>::size_type>);
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>>::const_iterator loc = wm.find(sought);

    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}