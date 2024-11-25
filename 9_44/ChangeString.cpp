#include "ChangeString.h"
#include <sstream>

void changeString(string& s, const string& oldVal, const string& newVal) {
    std::istringstream iss(s);
    string word;
    string::size_type pos = 0;
    while (iss >> word) {
        if (word == oldVal) {
            s.replace(pos, word.size(), newVal);
            pos += newVal.size();
        } else {
            pos += word.size();
        }
        ++pos;
    }
}