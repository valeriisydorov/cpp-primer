#include "ElimDups.h"
#include <algorithm>

void elimDups(vector<string>& words) {
    std::sort(words.begin(), words.end());
    vector<string>::iterator itUnique = std::unique(words.begin(), words.end());
    words.erase(itUnique, words.end());
}