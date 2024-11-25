#include "WordTransform.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <random>
#include <ctime>


using std::istringstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;


void wordTransform(ifstream& rulesFile, ifstream& inputFile, char& delim)
{
    map<string, string> transMap = buildMap(rulesFile, delim);

    string text;
    while (getline(inputFile, text))
    {
        istringstream isstream(text);
        string word;
        bool firstWord = true;
        while (isstream >> word)
        {
            if (firstWord)
            {
                firstWord = false;
            }
            else
            {
                cout << " ";
            }
            cout << transform(word, transMap);
        }
        cout << endl;
    }
}

map<string, string> buildMap(ifstream& rulesFile, char& delim)
{
    map<string, string> transMap;

    static std::default_random_engine dre(time(nullptr));

    string key;
    string value;
    while (rulesFile >> key && getline(rulesFile, value))
    {
        vector<string> options;

        stringstream strstream(value);
        string option;
        while (getline(strstream, option, delim))
        {
            options.push_back(option);
        }

        if (!options.empty())
        {
            std::uniform_int_distribution<unsigned> uid(0, options.size() - 1);

            transMap[key] = options[uid(dre)];
        }
        else
        {
            throw std::runtime_error("no rule for " + key);
        }
    }

    return transMap;
}

const string& transform(const string& s, const map<string, string>& m)
{
    map<string, string>::const_iterator mapIt = m.find(s);

    if (mapIt != m.cend())
    {
        return mapIt->second;
    }
    else
    {
        return s;
    }
}