#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <map>
#include <utility>

int main() {
    std::ifstream ifsExample("../example.txt");
    std::ifstream ifsExclude("../exclude.txt");

    std::istream_iterator<std::string> inExclude(ifsExclude), eofExclude;
    std::istream_iterator<std::string> inExample(ifsExample), eofExample;
    std::set<std::string> exclude(inExclude, eofExclude);
    std::map<std::string, size_t> totalCount;

    std::string word;
    while (ifsExample >> word) {
        if (exclude.find(word) == exclude.end()) {
            std::pair<std::map<std::string, size_t>::iterator, bool> ret = totalCount.insert({word, 1});
            if (!ret.second) {
                ++((ret.first)->second);
            }
        }
    }

    std::map<const std::string, unsigned long>::const_iterator mapIt = totalCount.cbegin();

    while (mapIt != totalCount.cend()) {
        std::cout << "\"" << mapIt->first << "\" occurs " << mapIt->second
            << ((mapIt->second > 1) ? " times" : " time") << std::endl;
        mapIt++;
    }

    return 0;
}
