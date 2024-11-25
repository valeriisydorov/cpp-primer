#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main() {
    vector<string> vi{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int totalInteger = 0;
    for (vector<string>::iterator it = vi.begin(); it != vi.end(); ++it) {
        totalInteger += std::stoi(*it);
    }
    std::cout << totalInteger << std::endl;

    vector<string> vd{"1.618033988", "2.71828182845904523536", "3.14159265359"};
    double totalDouble = 0.0;
    for (vector<string>::iterator it = vd.begin(); it != vd.end(); ++it) {
        totalDouble += std::stod(*it);
    }
    std::cout << totalDouble << std::endl;

    return 0;
}
