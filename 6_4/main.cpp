#include <iostream>
using std::cin; using std::cout; using std::endl;

int fact(int val)
{
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

int main()
{
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    int j = fact(n);
    cout << n << "! = " << j << endl;

    return 0;
}