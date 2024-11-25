#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "CheckString.h"

int main() {
    std::ifstream ifs("../example.txt");

    std::vector<std::string> source;
    std::string word;
    while (ifs >> word) {
        source.push_back(word);
    }

    size_t n = 10;
    size_t count = std::count_if(source.begin(), source.end(), CheckString(n));

    std::cout << count << std::endl;

    return 0;
}
