#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::noskipws;

int main() {
    unsigned qtyFf = 0, qtyFl = 0, qtyFi = 0;
    bool isF = false;

    char ch;
    while (cin >> noskipws >> ch) {
        if (!isF && (ch == 'f' || ch == 'F')) {
            isF = true;
        } else if (isF && (ch == 'f')) {
            ++qtyFf;
            isF = false;
        } else if (isF && (ch == 'l')) {
            ++qtyFl;
            isF = false;
        } else if (isF && (ch == 'i')) {
            ++qtyFi;
            isF = false;
        } else if (isF) {
            isF = false;
        }
    }

    cout << "Number of ff: " << qtyFf << endl;
    cout << "Number of fl: " << qtyFl << endl;
    cout << "Number of fi: " << qtyFi << endl;

    return 0;
}
