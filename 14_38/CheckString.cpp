#include "CheckString.h"

bool CheckString::operator()(const std::string& s) const {
    return s.size() <= size;
}
