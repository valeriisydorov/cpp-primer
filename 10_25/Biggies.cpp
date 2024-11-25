#include "Biggies.h"
#include <algorithm>
#include <iostream>
#include <functional>

void elimDups(vector<string>& words) {
    std::sort(words.begin(), words.end());
    vector<string>::iterator itUnique = std::unique(words.begin(), words.end());
    words.erase(itUnique, words.end());
}

bool check_size(string& s, vector<string>::size_type size) {
    return s.size() >= size;
}

void biggies(vector<string>& words, vector<string>::size_type size) {
    elimDups(words);

    std::stable_sort(words.begin(),words.end(),[](const string& s1, const string& s2) -> bool {
        return s1.size() < s2.size();
    });

    vector<string>::iterator itDelimiter = std::partition(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, size));

    vector<string>::size_type count = itDelimiter - words.begin();
    std::cout << count << (count == 1 ? " word" : " words") << " of length " << size << " or longer." << std::endl;

    std::for_each(words.begin(), itDelimiter, [](const string& s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}