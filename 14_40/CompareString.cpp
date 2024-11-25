#include "CompareString.h"

bool CompareString::operator()(const std::string& s) const {
    return s.size() >= size;
}

bool CompareString::operator()(const std::string& s1, const std::string& s2) const {
    return s1.size() < s2.size();
}