#include "Biggies.h"
#include <algorithm>
#include <iostream>

void elimDups(vector<string>& words) {
    std::sort(words.begin(), words.end());
    vector<string>::iterator itUnique = std::unique(words.begin(), words.end());
    words.erase(itUnique, words.end());
}

void biggies(vector<string>& words, vector<string>::size_type size) {
    elimDups(words);

    std::stable_sort(words.begin(),words.end(),[] (const string& s1, const string& s2) -> bool {
        return s1.size() < s2.size();
    });

    vector<string>::iterator itDelimiter = std::stable_partition(words.begin(), words.end(), [size] (const string& s) -> bool {
        return s.size() >= size;
    });

    vector<string>::size_type count = std::count_if(words.begin(), itDelimiter, [size] (const string& s) -> vector<string>::size_type {
        return s.size() >= size;
    });

    std::cout << count << (count == 1 ? " word" : " words") << " of length " << size << " or longer." << std::endl;

    std::for_each(words.begin(), itDelimiter, [] (const string& s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}