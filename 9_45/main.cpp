#include <iostream>
#include "GetFullName.h"

int main() {
    string name{"Valerii Sydorov"}, pref{"Mr."}, suff{"Jr."};

    std::cout << getFullName(name, pref, suff) << std::endl;

    return 0;
}
