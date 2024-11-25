#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcat;
using std::strcpy;

int main() {
    char str1[9] = "Valerii ";
    char str2[8] = "Sydorov";
    char str3[16] = "";

    strcat(str1, str2);
    strcpy(str3, str1);
    cout << str3 << endl;

    return 0;
}
