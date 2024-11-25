#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> vs = {"In", "God", "We", "Trust"};
    std::for_each(vs.rbegin(), vs.rend(), [] (std::string& s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;

    return 0;
}
