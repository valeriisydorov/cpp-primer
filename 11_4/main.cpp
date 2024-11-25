#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <map>
#include <cctype>

int main() {
    std::ifstream ifsExample("../example.txt");
    std::ifstream ifsExclude("../exclude.txt");

    std::istream_iterator<std::string> inExclude(ifsExclude), eofExclude;
    std::istream_iterator<std::string> inExample(ifsExample), eofExample;
    std::set<std::string> exclude(inExclude, eofExclude);
    std::set<char> punctuation{'.', ',', ':', ';', '?', '!'};
    std::map<std::string, size_t> counted;

    std::string word;
    while (ifsExample >> word) {
        std::string::iterator begin = word.begin();
        if (std::islower(*begin)) {
            *begin = std::toupper(*begin);
        }

        std::string::reverse_iterator end = word.rbegin();
        if (punctuation.find(*end) != punctuation.end()) {
            word.pop_back();
        }

        if (exclude.find(word) == exclude.end()) {
            ++counted[word];
        }
    }

    for (const auto &w: counted) {
        std::cout << "\"" << w.first << "\" occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    }

    return 0;
}
