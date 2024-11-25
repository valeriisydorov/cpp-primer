#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;

int main() {
    map<string, vector<string>> families = { {"Sydorov" , {"Cyril", "Arina"}}};
    families["Sydorov"].push_back("Fisya");
    families.insert({"Rostovsky", {"Artem", "Anya"}});
    families["Rostovsky"].push_back("Tihon");

    for (const auto& f: families) {
        std::cout << f.first << "'s: ";
        for (const string& name: f.second) {
            std::cout << name << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}