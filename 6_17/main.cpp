#include <iostream>
#include <string>
using std::string;

bool isUpperSymbol(const string &s)
{
    for (const char c: s) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

void toLowerCase(string &s)
{
    for (char &c: s) {
        if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }
}

int main() {
    string s = "Valerii Sydorov";
    std::cout << std::boolalpha << isUpperSymbol(s) << std::endl;

    toLowerCase(s);
    std::cout << s << std::endl;

    return 0;
}
