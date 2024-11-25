#include <iostream>
#include <string>
#include <cstring>

using std::string;
using std::cout;
using std::endl;


int main() {
    string str1 = "Valerii";
    string str2 = "Sydorov";

    if (str1 == str2) {
        cout << "str1 and str2 are equal" << endl;
    } else if (str1 > str2) {
        cout << "str1 is more than str2" << endl;
    } else {
        cout << "str1 is less than str2" << endl;
    }

    const char cstr1[] = "Valerii";
    const char cstr2[] = "Sydorov";

    if (strcmp(cstr1, cstr2) == 0) {
        cout << "cstr1 and cstr2 are equal" << endl;
    } else if (strcmp(cstr1, cstr2) > 0) {
        cout << "cstr1 is more than cstr2" << endl;
    } else {
        cout << "str1 is less than str2" << endl;
    }

    return 0;
}
