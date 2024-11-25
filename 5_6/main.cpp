#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;

int main() {
    vector<string> scores = {"A", "B", "C", "D", "F"};
    int grade = 100;
    string letter;
    
    cout << "You grade is: " 
    	 << (grade < 60 ? letter = scores[4] : grade < 100 ? grade % 10 < 3 ? letter = scores[(99 - grade) / 10] + "-" : grade % 10 > 7 ? letter = scores[(99 - grade) / 10] + "+" : letter = scores[(99 - grade) / 10] : letter = scores[0] + "++");

    return 0;
}
