#pragma once


#include "Sales_data.h"
#include <tuple>
#include <vector>
#include <string>
#include <iostream>


using std::tuple;
using std::vector;
using std::string;
using store = vector<Sales_data>;
using stores = vector<vector<Sales_data>>;
using matches = tuple<
    vector<Sales_data>::size_type,
    vector<Sales_data>::const_iterator,
    vector<Sales_data>::const_iterator
>;

vector<matches> findBook(const stores& files, const string& book);

void reportResult(std::istream& in, std::ostream& os, const stores& files);
