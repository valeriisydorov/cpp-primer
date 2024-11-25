#include <iostream>
#include <stack>
#include <string>
#include <array>

using std::stack;
using std::string;
using std::array;

int main() {
    const string expr("(A and B) or (C and D) or (E and F) or (J and H)");
    stack<string> bracketExpr;
    const array<char, 2> brackets{'(', ')'};

    string::size_type openBracketPos = 0;

    for (string::size_type i = 0; i != expr.size(); ++i) {
        if (expr[i] == brackets[0]) {
            openBracketPos = i;
        } else if (expr[i] == brackets[1]) {
            bracketExpr.push(expr.substr(openBracketPos, i - openBracketPos + 1));
        }
    }

    while (!bracketExpr.empty()) {
        string topElement = bracketExpr.top();
        std::cout << topElement << "\n";
        bracketExpr.pop();
    }

    return 0;
}