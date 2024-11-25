#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> ex = {{1, "Hey"}, {2, "Hello"}};
    std::map<int, std::string>::iterator it = ex.begin();
    it->second = "Goodbye";

    while (it != ex.end()) {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }

    return 0;
}
