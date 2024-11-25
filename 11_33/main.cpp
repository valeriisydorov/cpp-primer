#include "WordTransform.h"

int main() {
    ifstream rules("../rules");
    ifstream input("../input");

    wordTransform(rules, input);

    return 0;
}
