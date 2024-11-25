#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>

int main() {
    std::ifstream ifsExample("../example.txt");
    std::ifstream ifsExclude("../exclude.txt");

    std::istream_iterator<std::string> inExclude(ifsExclude), eofExclude;
    std::istream_iterator<std::string> inExample(ifsExample), eofExample;
    std::vector<std::string> exclude(inExclude, eofExclude);
    std::map<std::string, size_t> counted;

    std::string word;
    while (ifsExample >> word) {
        std::vector<std::string>::iterator it = std::find(exclude.begin(), exclude.end(), word);
        if (*it != word) {
            ++counted[word];
        }
    }

    for (const auto &w: counted) {
        std::cout << "\"" << w.first << "\" occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    }

    return 0;
}
