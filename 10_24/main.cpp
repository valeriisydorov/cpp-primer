#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool check_size(int& i, std::string& s) {
    return i > s.size();
}

int main() {
    std::vector<int> v{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    std::string s("Valerii Sydorov");

    std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), std::bind(check_size, std::placeholders::_1, s));
    std::cout << *it << std::endl;

    return 0;
}
