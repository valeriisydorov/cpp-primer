#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
    string qst;
    do {
        cout << "Enter first string: ";
        string str1;
        cin  >> str1;
        cout << "Enter second string: ";
        string str2;
        cin  >> str2;

        if (str1 > str2) {
            cout << "\"" << str1 << "\" is more then \"" << str2 << "\"" << endl;
        } else if (str1 < str2) {
            cout << "\"" << str1 << "\" is less then \"" << str2 << "\"" << endl;
        } else {
            cout << "\"" << str1 << "\" and \"" << str2 << "\" are equal" << endl;
        }

        cout << "More? Enter \"yes\" or \"no\": ";
        cin  >> qst;
    } while (!qst.empty() && qst != "no");

    cout << endl;

    return 0;
}