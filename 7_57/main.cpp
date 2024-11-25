#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Account.h"

int main()
{
    Account acc("bem", 42.5);
    cout << acc.getAmount() << endl;
    acc.calculate();
    cout << acc.getAmount() << endl;

    return 0;
}