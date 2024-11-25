#ifndef WORDTRANSFORM_H
#define WORDTRANSFORM_H

#include <fstream>
using std::ifstream;

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

void wordTransform(ifstream&, ifstream&);

unordered_map<string, string> buildMap(ifstream&);

const string& transform(const string&, const unordered_map<string, string>&);

#endif
