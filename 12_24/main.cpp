#include <iostream>
#include <cstring>

int main() {
    size_t maxSize = 10;
    char* str = new char[maxSize];

    std::cin.getline(str, maxSize);

    size_t size = strlen(str) + 1;

    char* result = new char[size];
    strcpy(result, str);

    std::cout << result << std::endl;

    delete[] str;
    delete[] result;

    return 0;
}