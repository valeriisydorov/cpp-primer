#include "GetFullName.h"

string getFullName(string& name, const string& pref, const string& suff) {
    string::iterator it = name.begin();
    name.insert(it, pref.begin(), pref.end());
    name.insert(pref.size(), " ");
    return name.append(" " + suff);
}