#include <iostream>
#include "ChangeString.h"

int main() {
    string s{"My dear bro remember that big bro is watching you."}, oldVal{"bro"}, newVal{"brother"};
    changeString(s, oldVal, newVal);

    std::cout << s << std::endl;

    return 0;
}
