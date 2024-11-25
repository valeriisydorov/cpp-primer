#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sequence;
    int number;
    while (std::cin >> number) {
        sequence.push_back(number);
    }
    const int value = 13;
    const int result = std::count(sequence.begin(), sequence.end(), value);
    std::cout << result << std::endl;

    return 0;
}
