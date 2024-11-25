#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned qtyA = 0, qtyE = 0, qtyI = 0, qtyO = 0, qtyU = 0;

    char ch;
    while (cin >> ch) {
        if (ch == 'a') {
            ++qtyA;
        } else if (ch == 'e') {
            ++qtyE;
        } else if (ch == 'i') {
            ++qtyI;
        } else if (ch == 'o') {
            ++qtyO;
        } else if (ch == 'u') {
            ++qtyU;
        }
    }

    cout << "Number of a: " << qtyA << endl;
    cout << "Number of e: " << qtyE << endl;
    cout << "Number of i: " << qtyI << endl;
    cout << "Number of o: " << qtyO << endl;
    cout << "Number of u: " << qtyU << endl;

    return 0;
}
