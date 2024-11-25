#include <iostream>
#include "TextQuery.h"
#include "RunQueries.h"
#include "Query.h"
#include "QueryResult.h"


int main() {
    std::ifstream ifs("../example.txt");
    TextQuery textQuery(ifs);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    QueryResult results = q.eval(textQuery);

    print(std::cout, results);

    return 0;
}