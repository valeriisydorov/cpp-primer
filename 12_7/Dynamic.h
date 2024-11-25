#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <memory>
using std::shared_ptr, std::make_shared;

#include <vector>
using std::vector;

shared_ptr<vector<int>> createVector();

void readVector(vector<int>&);

void writeVector(vector<int>&);

#endif
