#ifndef BIGGIES_H
#define BIGGIES_H

#include <vector>
#include <string>

using std::vector;
using std::string;

void elimDups(vector<string>&);
bool isShorter(const string&, const string&);
bool isShorterThan(const string&, string::size_type);
void print(const string&);
void biggies(vector<string>&, vector<string>::size_type);

#endif
