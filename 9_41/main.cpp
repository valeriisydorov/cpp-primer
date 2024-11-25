#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<char> v{'H', 'e', 'l', 'l', 'o', ' ', 'V', 'a', 'l', 'e', 'r', 'i', 'i', '!'};
    std::string s(v.begin(), v.end());
    std::cout << s << '\n';

    return 0;
}
