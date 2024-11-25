#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>

int main() {
    std::ifstream ifs("../example.txt");
    std::vector<std::string> srcFile;
    std::map<std::string, std::set<std::vector<std::string>::size_type>> wordsMap;

    std::string line;
    while (getline(ifs, line)) {
        srcFile.push_back(line);
        int n = srcFile.size() - 1;

        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            wordsMap[word].insert(n);
        }
    }

    do {
        std::cout << "Enter word to look for, or q to quit: ";
        std::string str;
        if (!(std::cin >> str) || str == "q") {
            break;
        } else {
            std::map<std::string, std::set<std::vector<std::string>::size_type>>::const_iterator it = wordsMap.find(str);
            if (it == wordsMap.end()) {
                std::cout << str << " is not in the file" << std::endl;
            } else {
                std::set<std::vector<std::string>::size_type>::const_iterator setIt = it->second.begin();
                while (setIt != it->second.end()) {
                    std::cout << srcFile[*setIt++] << std::endl;
                }
                std::cout << std::endl;
            }
        }
    } while (true);

    return 0;
}
