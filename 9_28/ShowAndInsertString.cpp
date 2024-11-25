#include "ShowAndInsertString.h"

void showAndInsertString(forward_list<string>& flstr, string& str1, string& str2) {
    forward_list<string>::iterator before = flstr.before_begin(), begin = flstr.begin();
    for (; begin != flstr.end(); ++begin, ++before) {
        if (*begin == str1) {
            flstr.insert_after(begin, str2);
            return;
        }
    }
    flstr.insert_after(before, str2);
}
