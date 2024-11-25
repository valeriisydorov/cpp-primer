#include <iostream>
#include "RunQueries.h"
#include "Query.h"


int main() {
//    std::ifstream ifs("../example.txt");
//    runQueries(ifs);

    Query q = Query("fiery") & Query("bird") | Query("wind");

    std::cout << q << std::endl;

    return 0;
}