#include "RunQueries.h"

int main() {
    std::ifstream ifs("../example.txt");
    runQueries(ifs);

    return 0;
}
