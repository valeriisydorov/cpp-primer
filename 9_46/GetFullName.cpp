#include "GetFullName.h"

string getFullName(string& name, const string& pref, const string& suff) {
    name.insert(0, pref + " ");
    name.insert(name.size(), " " + suff, 0, suff.size() + 1);
    return name;
}