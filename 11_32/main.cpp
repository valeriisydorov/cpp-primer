#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::multimap<std::string, std::string> library = {{"Donald Knuth", "The Art of Computer Programming"},
                                                       {"Donald Knuth", "Stable Marriage and Its Relation to Other Combinatorial Problems"},
                                                       {"Edsger Dijkstra", "A Discipline of Programming"},
                                                       {"David Gries", "The Science of Programming"},
                                                       {"Jon Bentley", "Programming Pearls"}};

    std::vector<std::pair<std::string, std::string>> temp;

    for (const std::pair<std::string, std::string>& pair : library) {
        temp.push_back(pair);
    }

    std::sort(temp.begin(), temp.end(), [] (const std::pair<std::string, std::string>& p1, const std::pair<std::string, std::string>& p2) -> bool {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        } else {
            return p1.second < p2.second;
        }
    });

    for (const std::pair<std::string, std::string>& p: temp) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}