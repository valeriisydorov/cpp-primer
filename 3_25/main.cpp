#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<unsigned> grades;

    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100) {
            grades.push_back(grade);
        }
        auto scoreIt = scores.begin();
        scoreIt += grade / 10;
        ++*scoreIt;
    }

    cout << "grades.size = " << grades.size() << endl;
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "scores.size = " << scores.size() << endl;
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        cout << *it << " " ;
    }
    cout << endl;

    return 0;
}