#include <sstream>
#include <string>
#include "GetStream.h"

int main() {
    std::string myStr = {"Albert Einstein"};
    std::istringstream strm(myStr);

    getStream(strm);

    return 0;
}
