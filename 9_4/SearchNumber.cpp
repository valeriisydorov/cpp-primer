#include "SearchNumber.h"

bool searchNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end, int num)
{
    bool result = false;
    while (begin != end) {
        if (*begin == num) {
            result = true;
        }
        ++begin;
    }
    return result;
}