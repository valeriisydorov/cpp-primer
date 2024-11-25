#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    string word, prevWord;

    while (cin >> word && !word.empty()) {
        if (!isupper(word[0])) {
            continue;
        }
        if (word == prevWord) {
            cout << "The word \"" << word << "\" is duplicated." << endl;
            break;
        } else {
            prevWord = word;
        }
    }

    if (cin.eof()) {
        cout << "No duplicate words." << endl;
    }

    return 0;
}