#include "Put_text_into_vector.h"
#include <iostream>

int main() {
    vector<string> vec;
    putTextIntoVector(vec, "../Let_it_be.txt");
    for (string& elem: vec) {
        std:: cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
