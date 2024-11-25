#include <iostream>
#include <sstream>

#include <vector>
#include <algorithm>

#include "MoreThanFour.h"

using std::vector;

int main() {
    string tale{"the quick red fox jumps over the slow red turtle"};

    std::istringstream iss(tale);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    vector<string>::iterator itDelimiter = std::partition(words.begin(), words.end(), moreThanFour);

    for (vector<string>::iterator it = words.begin(); it != itDelimiter; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}