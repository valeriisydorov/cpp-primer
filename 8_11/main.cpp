#include <iostream>
#include <sstream>
#include "PersonInfo.h"

using std::istringstream;

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(std::cin, line)) {
        PersonInfo info;
        record.str(line);
        record.clear();
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    return 0;
}
