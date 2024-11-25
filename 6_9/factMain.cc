#include <iostream>
#include "Chapter6.h"

using std::cin; using std::cout; using std::endl;

int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    int i = fact(n);
    cout << n << "! = " << i << endl;

    return 0;
}