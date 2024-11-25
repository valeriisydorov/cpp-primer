#include "Dynamic.h"

#include <iostream>
using std::cin, std::cout, std::endl;

shared_ptr<vector<int>> createVector() {
    shared_ptr<vector<int>> vi = make_shared<vector<int>>();
    return vi;
}

void readVector(vector<int>& vi) {
    int i;
    while (cin >> i) {
        vi.push_back(i);
    }
}

void writeVector(vector<int>& vi) {
    for (int& i: vi) {
        cout << i << " ";
    }
    cout << endl;
}
