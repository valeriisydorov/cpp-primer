#include "CompareElements.h"

bool compareElements(std::list<int>& l, std::vector<int>& v) {
    std::vector<int> temp;
    temp.assign(l.begin(), l.end());
    return temp < v;
}