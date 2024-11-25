#include <iostream>
#include "Put_text_into_vector.h"

int main() {
    vector<string> vec;
    putTextIntoVector(vec, "../Let_it_be.txt");
    for (string& elem: vec) {
        std::cout << elem << std::endl;
    }

    return 0;
}
