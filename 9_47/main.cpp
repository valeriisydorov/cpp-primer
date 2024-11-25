#include <iostream>
#include <string>

using std::string;

int main() {
    string s{"ab2c3d7R4E6"};
    string numbers;
    for (int i = 0; i != 10 ; ++i) {
        numbers.append(std::to_string(i));
    }

    string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != string::npos) {
        std::cout << "Number at index: " << pos << " element is " << s[pos] << std::endl;
        ++pos;
    }
    std::cout << std::endl;

    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
        std::cout << "Letter at index: " << pos << " element is " << s[pos] << std::endl;
        ++pos;
    }

    return 0;
}
