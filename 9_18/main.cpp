#include <iostream>
#include <deque>
#include <string>

int main() {
    std::deque<std::string> cont;
    std::string str;
    std::deque<std::string>::iterator it = cont.begin();

    while (getline(std::cin, str)) {
        it = cont.insert(it, str);
    }

    for (std::string& line: cont) {
        std::cout << line << std::endl;
    }

    return 0;
}
