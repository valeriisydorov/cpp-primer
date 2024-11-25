#include "BinaryQuery.h"

std::string BinaryQuery::rep() const {
    // TODO remove the output later
    std::cout << "BinaryQuery::rep()" << std::endl;
    return "(" + lhs.rep() + " " + opSymbol + " " + rhs.rep() + ")";
}
