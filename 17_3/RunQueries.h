#pragma once


#include "TextQuery.h"


void runQueries(std::ifstream&);
std::ostream& print(std::ostream&, TextQuery::TupleResult&);

