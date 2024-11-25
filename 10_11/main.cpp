#include <iostream>
#include <sstream>
#include "ElimDups.h"

int main() {
    string store{"the quick red fox jumps over the slow red turtle"};
    std::istringstream iss(store);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    elimDups(words);

    std::stable_sort(words.begin(), words.end(), isShorter);

    for (const string& w: words) {
        std::cout << w << " ";
    }

    return 0;
}
