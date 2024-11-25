#include <map>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::map<std::string, std::vector<int>> m;
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> it = m.insert(std::map<std::string, std::vector<int>>::value_type ("", {}));

    return 0;
}
