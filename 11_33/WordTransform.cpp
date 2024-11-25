#include "WordTransform.h"
#include <iostream>
#include <sstream>

using std::istringstream;
using std::cout;
using std::endl;

void wordTransform(ifstream& rulesFile, ifstream& input) {
    map<string, string> transMap = buildMap(rulesFile);
    string text;
    while (getline(input, text)) {
        istringstream isstream(text);
        string word;
        bool firstWord = true;
        while (isstream >> word) {
            if (firstWord) {
                firstWord = false;
            } else {
                cout << " ";
            }
            cout << transform(word, transMap);
        }
        cout << endl;
    }
}

map<string, string> buildMap(ifstream& rulesFile) {
    map<string, string> transMap;
    string key;
    string value;
    while (rulesFile >> key && getline(rulesFile, value)) {
        if (value.size() > 1) {
            transMap[key] = value.substr(1);
//            transMap.insert({key, value.substr(1)});
        } else {
            throw std::runtime_error("no rule for " + key);
        }
    }
    return transMap;
}

const string& transform(const string& s, const map<string, string>& m) {
    map<string, string>::const_iterator mapIt = m.find(s);
    if (mapIt != m.cend()) {
        return mapIt->second;
    } else {
        return s;
    }
}