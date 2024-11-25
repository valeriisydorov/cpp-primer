#include <iostream>
using std::cin; using std::cout; using std::endl;

int modulus(int val)
{
    return val < 0 ? -val : val;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int j = modulus(n);
    cout << "|"<< n << "| = " << j << endl;

    return 0;
}