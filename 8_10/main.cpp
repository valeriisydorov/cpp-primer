#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> content;
    std::string fname{"../example.txt"};
    std::ifstream fstrm;
    fstrm.open(fname);
    if (fstrm) {
        std::string str;
        while (std::getline(fstrm, str)) {
            content.push_back(str);
        }
        fstrm.clear();
    }
    fstrm.close();

    for (std::string& line: content) {
        std::istringstream sstrm(line);
        std::string word;
        while (sstrm >> word) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
