#pragma once


#include <fstream>
#include <map>
#include <string>


using std::ifstream;
using std::map;
using std::string;


void wordTransform(ifstream&, ifstream&, char&);

map<string, string> buildMap(ifstream&, char&);

const string& transform(const string&, const map<string, string>&);
