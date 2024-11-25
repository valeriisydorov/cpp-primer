#include "ReadString.h"

std::string ReadString::operator()() {
    std::string input;
    if (is >> input) {
        return input;
    } else {
        return "";
    }
}