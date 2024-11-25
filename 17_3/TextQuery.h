#pragma once


#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include "StrBlob.h"
#include "StrBlobPtr.h"


class TextQuery
{
public:
    using TupleResult = std::tuple<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>, StrBlob>;

    TextQuery(std::ifstream&);
    TupleResult query(const std::string&) const;
private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> wm;
};
