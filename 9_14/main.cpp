#include <iostream>
#include <vector>
#include <list>
#include <string>

int main() {
    std::list<char*> oldstyle{"Valerii", "Vasylovych", "Sydorov"};
    std::vector<std::string> newstyle;
    newstyle.assign(++oldstyle.begin(), --oldstyle.end());

    for (std::string str: newstyle) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
