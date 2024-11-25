#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <map>

int main() {
    std::ifstream ifsExample("../example.txt");
    std::ifstream ifsExclude("../exclude.txt");

    std::istream_iterator<std::string> inExclude(ifsExclude), eofExclude;
    std::istream_iterator<std::string> inExample(ifsExample), eofExample;
    std::set<std::string> exclude(inExclude, eofExclude);
    std::map<std::string, size_t> counted;

    std::string word;
    while (ifsExample >> word) {
        if (exclude.find(word) == exclude.end()) {
            ++counted[word];
        }
    }

    std::map<const std::string, unsigned long>::const_iterator map_it = counted.cbegin();

    while (map_it != counted.cend()) {
        std::cout << "\"" << map_it->first << "\" occurs " << map_it->second << ((map_it->second > 1) ? " times" : " time") << std::endl;
        map_it++;
    }

    return 0;
}
