#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main() {
    int num1, num2;
    cout << "Enter two numbers:" << endl;

    while (cin >> num1 >> num2) {
        try {
            if (num2 == 0) {
                throw runtime_error("Cannot be divided by zero.");
            }
            cout << num1 << " : " << num2 << " = " << num1 / num2;
            cout << endl;
            break;
        } catch (runtime_error err) {
            cout << err.what() << endl;
            cout << "Try again? Enter \"y\" or \"n\":" << endl;
            char c;
            cin >> c;

            if (!cin || c == 'y') {
                cout << "Enter two other numbers:" << endl;
                continue;
            } else {
                cout << "Bye." << endl;
                break;
            }
        }
    }

    return 0;
}
