#pragma once


#include "Matches.h"
#include <string>
#include <iostream>


using std::string;
using matches = Matches;
using store = matches::store;
using stores = vector<store>;

vector<matches> findBook(const stores& files, const string& book);

void reportResult(std::istream& in, std::ostream& os, const stores& files);
