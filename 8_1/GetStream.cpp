#include "GetStream.h"
#include <string>

std::istream& getStream(std::istream& s) {
    std::string word;
    while (!s.eof()) {
        s >> word;
        std::cout << word << std::endl;
    }
    s.clear();

    return s;
}