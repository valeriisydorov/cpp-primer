#include "ReadString.h"

std::string ReadString::operator()(const std::string& s) {
    if (is) {
        return s;
    } else {
        return "";
    }
}