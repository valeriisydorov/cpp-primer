#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::noskipws;

int main() {
    unsigned qtyA = 0, qtyE = 0, qtyI = 0, qtyO = 0, qtyU = 0, qtySp = 0, qtyNl = 0, qtyTb = 0;

    char ch;
    while (cin >> noskipws >> ch) {
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
        } else if (ch == ' ') {
            ++qtySp;
        } else if (ch == '\t') {
            ++qtyTb;
        } else if (ch == '\n') {
            ++qtyNl;
        }
    }

    cout << "Number of A & a: " << qtyA << endl;
    cout << "Number of E & e: " << qtyE << endl;
    cout << "Number of I & i: " << qtyI << endl;
    cout << "Number of O & o: " << qtyO << endl;
    cout << "Number of U & u: " << qtyU << endl;
    cout << "Number of spaces: " << qtySp << endl;
    cout << "Number of tab symbols: " << qtyTb << endl;
    cout << "Number of new line symbols: " << qtyNl << endl;

    return 0;
}
