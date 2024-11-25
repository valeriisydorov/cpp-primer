#include "Put_text_into_vector.h"
#include <fstream>

void putTextIntoVector(vector<string>& vec, string fname)
{
    std::ifstream fstrm(fname);
    if (fstrm) {
        string word;
        while (!fstrm.eof()) {
            fstrm >> word;
            vec.push_back(word);
        }
        fstrm.clear();
    }
}