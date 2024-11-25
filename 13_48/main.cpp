#include "String.h"
#include <vector>

int main() {
    String a = "Hello";
    String b = "Goodbye";

    std::vector<String> v;

    v.push_back(a);
    v.push_back(a);
    v.push_back(b);
    v.push_back(b);

    return 0;
}
