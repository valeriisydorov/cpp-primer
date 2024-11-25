#include "Biggies.h"
#include <algorithm>
#include <iostream>
#include <functional>

void elimDups(vector<string>& words) {
    std::sort(words.begin(), words.end());
    vector<string>::iterator itUnique = std::unique(words.begin(), words.end());
    words.erase(itUnique, words.end());
}

bool isShorter(const string& str1, const string& str2) {
    return str1.size() < str2.size();
}

bool isShorterThan(const string& str, string::size_type size) {
    return str.size() >= size;
}

void print(const string& str) {
    std::cout << str << " ";
}

void biggies(vector<string>& words, vector<string>::size_type size) {
    elimDups(words);

    std::stable_sort(words.begin(),words.end(), isShorter);

    vector<string>::iterator itDelimiter = std::stable_partition(words.begin(), words.end(), std::bind(isShorterThan, std::placeholders::_1, size));

    vector<string>::size_type count = std::count_if(words.begin(), itDelimiter, std::bind(isShorterThan, std::placeholders::_1, size));

    std::cout << count << (count == 1 ? " word" : " words") << " of length " << size << " or longer." << std::endl;

    std::for_each(words.begin(), itDelimiter, print);
    std::cout << std::endl;
}