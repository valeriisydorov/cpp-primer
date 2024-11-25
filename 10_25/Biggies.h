#ifndef BIGGIES_H
#define BIGGIES_H

#include <vector>
#include <string>

using std::vector;
using std::string;

void elimDups(vector<string>&);
bool check_size(string&, vector<string>::size_type);
void biggies(vector<string>&, vector<string>::size_type);

#endif
