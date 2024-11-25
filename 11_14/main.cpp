#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using std::map;
using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

int main() {
    map<string, vector<pair<string, string>>> families = { {"Sydorov" , {{"Cyril", "12 Apr 2002"}, {"Arina", "15 Dec 2010"}}}};
    families["Sydorov"].push_back(std::make_pair("Fysya", "30 Nov 2011"));
    families.insert({"Rostovsky", {{"Artem", "unknown"}, {"Anya", "unknown"}}});
    families["Rostovsky"].push_back(std::make_pair("Tyhon", "unknown"));

    for (const auto& f: families) {
        cout << "The family of " << f.first << "'s:" << endl;
        for (const auto & child: f.second) {
            cout << child.first << "'s birthday: " << child.second << endl;
        }
        cout << endl;
    }

    return 0;
}