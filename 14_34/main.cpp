#include <iostream>

#include "CheckValue.h"

int main() {
    CheckValue FirstGod;
    CheckValue SecondGod;
    std::string firstName = FirstGod("Jesus", "Yes", "No");
    std::string secondName = FirstGod("Buddha", "Yes", "No");
    std::cout << firstName << std::endl;
    std::cout << secondName << std::endl;
    return 0;
}
