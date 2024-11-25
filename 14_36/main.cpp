#include "ReadString.h"

#include <vector>

int main() {
    ReadString reader;
    std::vector<std::string> container;

    std::cout << "Enter strings or type 'exit' to stop:\n";

    while (true) {
        std::string input = reader();
        if (input == "exit") {
            break;
        }
        container.push_back(input);
    }

    std::cout << "Entered strings:\n";
    for (const std::string& s: container) {
        std::cout << s << "\n";
    }

    return 0;
}
