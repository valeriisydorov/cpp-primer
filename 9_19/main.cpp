#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> cont;
    std::string str;
    std::list<std::string>::iterator it = cont.begin();

    while (getline(std::cin, str)) {
        it = cont.insert(it, str);
    }

    for (std::string& line: cont) {
        std::cout << line << std::endl;
    }

    return 0;
}
