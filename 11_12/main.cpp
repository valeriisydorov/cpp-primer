#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::istream &is = std::cin;
    std::vector<std::pair<std::string, int>> data;

    std::string str;
    int num;

    while (!is.eof()) {
        std::cout << "Enter a string (or type 'done' to finish): ";
        is >> str;
        if (str == "done") {
            break;
        }
        std::cout << "Enter an integer: ";
        is >> num;
        std::pair<std::string, int> elem{str, num};
        data.push_back(elem);
    }

    for (std::pair<std::string, int>& el: data) {
        std::cout << el.first << " " << el.second << std::endl;
    }

    return 0;
}
