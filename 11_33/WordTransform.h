#ifndef WORDTRANSFORM_H
#define WORDTRANSFORM_H

#include <fstream>
using std::ifstream;

#include <map>
using std::map;

#include <string>
using std::string;

void wordTransform(ifstream&, ifstream&);

map<string, string> buildMap(ifstream&);

const string& transform(const string&, const map<string, string>&);

#endif
