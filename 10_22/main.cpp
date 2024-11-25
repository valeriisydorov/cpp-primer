#include "Biggies.h"
#include <sstream>

int main() {
    string store{"the quick red fox jumps over the slow red turtle"};
    std::istringstream iss(store);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    biggies(words, 6);

    return 0;
}
