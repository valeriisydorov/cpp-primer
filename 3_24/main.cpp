#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<int> numb3rs;
    string num;
    int temp;

    while (getline(cin, num)) {
        std::istringstream iss(num);
        while (iss >> temp) {
            numb3rs.push_back(temp);
        }
    }

    cout << endl;

    for (auto it = numb3rs.begin(); it < numb3rs.end(); it += 2) {
        cout << *it + *(it + 1) << " ";
    }

    cout << endl;

    for (auto beg = numb3rs.begin(), end = numb3rs.end(); beg != beg - (end - beg) / 2; ++beg, --end) {
        cout << *beg + *(end - 1) << " ";
        if (beg + 1 == end - 2) {
            cout << *(beg + 1) << " ";
        }
    }

    cout << endl;

    return 0;
}