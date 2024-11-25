#include <iostream>
using std::cout;
using std::endl;

#include "StrBlob.h"

int main()
{
    StrBlob b1;
    {
        const StrBlob b2 = { "a", "an", "the" };
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;

    return 0;
}