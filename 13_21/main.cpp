#include "RunQueries.h"

int main() {
    std::ifstream ifs("../example.txt");

//    runQueries(ifs);

    TextQuery tq(ifs);
    TextQuery tq2(tq);

    return 0;
}
