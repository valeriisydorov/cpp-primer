#include "SearchNumber.h"

std::vector<int>::iterator searchNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end, int number)
{
    std::vector<int>::iterator result = end;
    while (begin != end) {
        if (*begin == number) {
            result = begin;
        }
        ++begin;
    }
    return result;
}