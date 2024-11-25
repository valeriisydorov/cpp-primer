#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

int main() {
    std::ifstream ifs("../example.txt");
    std::istream_iterator<std::string> in(ifs);
    std::istream_iterator<std::string> eof;
    std::vector<std::string> vs(in, eof);

    for (std::string& str: vs) {
        std::cout << str << " ";
    }
    std::cout << "\n";

    return 0;
}
