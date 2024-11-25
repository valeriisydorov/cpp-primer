#include <map>
#include <vector>
#include <string>

int main() {
    std::map<std::string, std::vector<int>> m = {{"prime", {2, 3, 5, 7, 11, 13}},
                                                 {"even", {2, 4, 6, 8, 10, 12}},
                                                 {"odd", {1, 3, 5, 7, 9, 11}}};
    std::map<std::string, std::vector<int>>::const_iterator it = m.find("prime");

    return 0;
}
