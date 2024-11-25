#include "WordTransform.h"


int main()
{
    ifstream rules("../rules");
    ifstream input("../input");

    char rulesOptionsDelimiter = ',';

    wordTransform(rules, input, rulesOptionsDelimiter);

    return 0;
}
