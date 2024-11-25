#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned qtyA = 0, qtyE = 0, qtyI = 0, qtyO = 0, qtyU = 0;

    char ch;
    while (cin >> ch) {
        if (ch == 'a' || ch == 'A') {
            ++qtyA;
        } else if (ch == 'e' || ch == 'E') {
            ++qtyE;
        } else if (ch == 'i' || ch == 'I') {
            ++qtyI;
        } else if (ch == 'o' || ch == 'O') {
            ++qtyO;
        } else if (ch == 'u' || ch == 'U') {
            ++qtyU;
        }
    }

    cout << "Number of A & a: " << qtyA << endl;
    cout << "Number of E & e: " << qtyE << endl;
    cout << "Number of I & i: " << qtyI << endl;
    cout << "Number of O & o: " << qtyO << endl;
    cout << "Number of U & u: " << qtyU << endl;

    return 0;
}
