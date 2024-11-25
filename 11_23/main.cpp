#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::multimap;
using std::vector;
using std::string;

int main() {
    multimap<string, vector<string>> families = { {"Sydorov" , {"Cyril", "Arina"}}};
    families.begin()->second.push_back("Fisya");
    families.insert({"Rostovsky", {"Artem", "Anya"}});
    ++families.begin();
    families.begin()->second.push_back("Tihon");

    for (const auto& f: families) {
        std::cout << f.first << "'s: ";
        for (const string& name: f.second) {
            std::cout << name << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}