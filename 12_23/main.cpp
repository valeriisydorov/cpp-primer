#include <iostream>
#include <cstring>
#include <string>

int main() {
    const char* str1 = "Albert Einstein ";
    const char* str2 = "is one of the greatest and most influential scientists of all time.";
    size_t sz = strlen(str1) + strlen(str2) + 1;
    char* result = new char[sz];
    strcpy(result, str1);
    strcat(result, str2);

    std::cout << result << std::endl;
    delete [] result;

    std::string string1 = "Albert Einstein ";
    std::string string2 = "is one of the greatest and most influential scientists of all time.";
    std::string commonString = string1 + string2;
    char* stringResult = new char[commonString.size() + 1];
    strcpy(stringResult, commonString.c_str());

    std::cout << stringResult << std::endl;
    delete [] stringResult;


    return 0;
}
