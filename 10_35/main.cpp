#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vs = {"In", "God", "We", "Trust"};
    for (std::vector<std::string>::iterator it = vs.end() - 1; it != vs.begin() - 1; --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
