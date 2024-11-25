#include "CheckValue.h"

std::string CheckValue::operator()(const std::string& name, const std::string& truthful, const std::string& deceitful) const {
    if (name == god) {
        return truthful;
    } else {
        return deceitful;
    }
}