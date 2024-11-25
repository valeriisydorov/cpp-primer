#include "Dynamic.h"

#include <iostream>
using std::cin, std::cout, std::endl;

vector<int>* createVector() {
    vector<int> *vi = new vector<int>;
    return vi;
}

void readVector(vector<int>* vi) {
    int i;
    while (cin >> i) {
        (*vi).push_back(i);
    }
}

void writeVector(vector<int>* vi) {
    for (int& i: *vi) {
        cout << i << " ";
    }
    cout << endl;
}
