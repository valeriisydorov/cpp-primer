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

    size_t n = 9;
    size_t count = std::count_if(source.begin(), source.end(), CheckString(n));

    std::cout << "From 1 to 9: " << count << std::endl;
    std::cout << "From 10 and more: " << source.size() - count << std::endl;

    return 0;
}
