#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <unordered_map>

#include "WordTransform.h"

int main() {
    std::ifstream ifsExample("../example.txt");
    std::ifstream ifsExclude("../exclude.txt");

    std::istream_iterator<std::string> inExclude(ifsExclude), eofExclude;
    std::istream_iterator<std::string> inExample(ifsExample), eofExample;
    std::set<std::string> exclude(inExclude, eofExclude);
    std::unordered_map<std::string, size_t> counted;

    std::string word;
    while (ifsExample >> word) {
        if (exclude.find(word) == exclude.end()) {
            ++counted[word];
        }
    }

    for (const auto &w: counted) {
        std::cout << "\"" << w.first << "\" occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    }

    std::cout << std::endl;

    ifstream rules("../rules");
    ifstream input("../input");

    wordTransform(rules, input);

    return 0;
}
