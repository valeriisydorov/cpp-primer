#include "Put_text_into_vector.h"
#include <fstream>

void putTextIntoVector(vector<string>& vec, string fname)
{
    std::ifstream fstrm(fname);
    if (fstrm) {
        string str;
        while (std::getline(fstrm, str)) {
            vec.push_back(str);
        }
        fstrm.clear();
    }
}