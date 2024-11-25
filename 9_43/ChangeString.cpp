#include "ChangeString.h"
#include <sstream>

void changeString(string& s, const string& oldVal, const string& newVal) {
    std::istringstream iss(s);
    string word;
    string::size_type pos = 0;
    string::iterator it = s.begin();
    while (iss >> word) {
        if (word == oldVal) {
            s.erase(pos, word.size());
            it = s.insert(it, newVal.begin(), newVal.end());
            it += static_cast<unsigned int>(newVal.size());
            pos += newVal.size();
        } else {
            it += static_cast<unsigned int>(word.size());
            pos += word.size();
        }
        ++it;
        ++pos;
    }
}