#include <iostream>
#include <fstream>
#include <sstream>
#include "PersonInfo.h"

using std::ifstream;
using std::istringstream;

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream data("../data.txt");

    while (getline(data, line)) {
        PersonInfo info;
        record.str(line);
        record.clear();
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (const auto &entry : people) {
        std::ostringstream numbers;
        for (const auto &nums : entry.phones) {
            numbers << " " << nums;
        }
        std::cout << entry.name << ":" << numbers.str() << std::endl;
    }

    return 0;
}
