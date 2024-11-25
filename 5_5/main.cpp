#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;

int main() {
    vector<string> scores = {"A", "B", "C", "D", "F"};
    int grade = 75;
    string lettergrade;

    if (grade < 60) {
        lettergrade = scores[4];
    } else if (grade < 100) {
        lettergrade = scores[(99 - grade) / 10];
        if (grade % 10 < 3) {
            lettergrade += "-";
        } else if (grade % 10 > 7) {
            lettergrade += "+";
        }
    } else {
        lettergrade = scores[0] + "++";
    }

    cout << "You grade is: " << lettergrade;

    return 0;
}
