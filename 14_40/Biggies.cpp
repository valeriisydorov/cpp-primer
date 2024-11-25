#include "Biggies.h"
#include "CompareString.h"
#include <algorithm>
#include <iostream>

void elimDups(vector<string>& words) {
    std::sort(words.begin(), words.end());
    vector<string>::iterator itUnique = std::unique(words.begin(), words.end());
    words.erase(itUnique, words.end());
}

void biggies(vector<string>& words, vector<string>::size_type size) {
    elimDups(words);

    std::stable_sort(words.begin(),words.end(), CompareString());

    vector<string>::iterator itDelimiter = std::find_if(words.begin(), words.end(), CompareString(size));

    vector<string>::size_type count = words.end() - itDelimiter;
    std::cout << count << (count == 1 ? " word" : " words") << " of length " << size << " or longer." << std::endl;

    std::for_each(itDelimiter, words.end(), [](const string& s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}