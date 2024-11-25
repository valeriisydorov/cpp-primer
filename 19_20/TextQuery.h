#pragma once


#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>


class TextQuery
{
public:
    class QueryResult
    {
        friend std::ostream& print(std::ostream&, const QueryResult&);

    public:
        QueryResult(std::string s, std::shared_ptr<std::set<std::vector<std::string>::size_type>>p, std::shared_ptr<std::vector<std::string>> f)
        : sought(s)
        , lines(p)
        , file(f)
        {
        }

        std::set<std::vector<std::string>::size_type>::const_iterator begin() const
        {
            return lines->cbegin();
        }
        std::set<std::vector<std::string>::size_type>::const_iterator end() const
        {
            return lines->cend();
        }
        std::shared_ptr<std::vector<std::string>> get_file()
        {
            return file;
        }

    private:
        std::string sought;
        std::shared_ptr<std::set<std::vector<std::string>::size_type>> lines;
        std::shared_ptr<std::vector<std::string>> file;
    };

    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> wm;
    
};
