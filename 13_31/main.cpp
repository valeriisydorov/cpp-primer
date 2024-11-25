#include "HasPtr.h"

#include <vector>
#include <algorithm>

int main() {
    std::vector<HasPtr> v;
    HasPtr item1("Valerii"), item2("Arina"), item3("Cyrill"), item4("Irina");
    v.push_back(item1);
    v.push_back(item2);
    v.push_back(item3);
    v.push_back(item4);

    std::sort(v.begin(), v.end());

    return 0;
}
