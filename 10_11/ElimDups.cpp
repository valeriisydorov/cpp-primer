#include "ElimDups.h"

void elimDups(vector<string>& words) {
    std::sort(words.begin(), words.end());
    vector<string>::iterator itUnique = std::unique(words.begin(), words.end());
    words.erase(itUnique, words.end());
}

bool isShorter(const string& str1, const string& str2) {
    return str1.size() < str2.size();
}