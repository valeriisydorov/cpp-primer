#include <iostream>
#include <string>
#include <fstream>

using std::string;

int main() {
    std::ifstream fs("../birds.txt");

    string exceptions("dfghjklpqt");
    string maxWord;
    string word;

    while (fs >> word) {
        string::size_type pos = word.find_first_of(exceptions);
        if (pos == string::npos && word.size() > maxWord.size()) {
            maxWord = word;
        }
    }

    std::cout << maxWord << std::endl;

    return 0;
}
