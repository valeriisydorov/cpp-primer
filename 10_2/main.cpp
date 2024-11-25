#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int main() {
    std::list<std::string> sequence;
    std::string word;
    while (std::cin >> word) {
        sequence.push_back(word);
    }
    std::string value = "Hack";
    const int result = std::count(sequence.begin(), sequence.end(), value);
    std::cout << result << std::endl;

    return 0;
}