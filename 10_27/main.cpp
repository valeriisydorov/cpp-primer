#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::string;
using std::vector;

int main() {
    string phrase{"the quick red fox jumps over the slow red turtle"};
    std::istringstream iss(phrase);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    std::sort(words.begin(), words.end());
    vector<string> uniqueWords;
    std::unique_copy(words.begin(), words.end(), std::back_inserter(uniqueWords));

    std::for_each(uniqueWords.begin(), uniqueWords.end(), [] (string& s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;

    return 0;
}