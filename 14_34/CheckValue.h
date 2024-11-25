#ifndef CHECKVALUE_H
#define CHECKVALUE_H

#include <string>

struct CheckValue {
    std::string operator()(const std::string&, const std::string&, const std::string&) const;
    const std::string god = "Buddha";
};

#endif
