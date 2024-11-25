#include <iostream>

using std::string;
using std::cout;
using std::cin;

int main() {
    string word;

    unsigned maxCnt = 0;
    unsigned currCnt = 0;
    string maxWord;
    string currWord;

    while (cin >> word) {
        if (word != currWord) {
            if (currCnt > maxCnt) {
                maxCnt = currCnt;
                maxWord = currWord;
            }
            currCnt = 1;
            currWord = word;
        } else {
            ++currCnt;
        }
    }
    if (currCnt > maxCnt) {
        maxCnt = currCnt;
        maxWord = currWord;
    }

    cout << "The word \"" << maxWord << "\" occurs " << maxCnt << " times in the row.";

    return 0;
}
