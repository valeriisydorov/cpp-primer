#include <iostream>
#include <fstream>
using std::cout;
using std::endl;

#include "StrBlob.h"
#include "StrBlobPtr.h"

int main(int argc, char* argv[])
{
    char *ifn = argv[1];
    std::ifstream ifs(ifn);
    std::string str;
    StrBlob a;
    while (getline(ifs, str)) {
        a.push_back(str);
    }

    StrBlobPtr b(a);

    while (!a.empty()) {
        cout << b.deref() << endl;
        b.incr();
    }

    return 0;
}