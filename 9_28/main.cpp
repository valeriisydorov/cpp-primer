#include "ShowAndInsertString.h"
#include <iostream>

int main()
{
    forward_list<string> fl = {"Arina", "Cyril", "Ira", "Valerii"};
    string s1 = "Cyril", s2 = "Fisia";

    showAndInsertString(fl, s1, s2);

    for (string &s: fl) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    return 0;
}