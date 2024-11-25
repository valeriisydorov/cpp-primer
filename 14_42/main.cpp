#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    int arr[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    std::greater<int> intGreater;

    int n = 1024;
    size_t count = std::count_if(std::begin(arr), std::end(arr), std::bind(intGreater, std::placeholders::_1, n));
    std::cout << count << std::endl;

    std::vector<std::string> stringVector = {"Pooh", "Pooh", "Pooh", "Winnie-The-Pooh", "Pooh"};
    std::equal_to<std::string> stringEqualTo;

    std::string s = "Pooh";
    std::vector<std::string>::iterator it = std::find_if_not(stringVector.begin(), stringVector.end(), std::bind(stringEqualTo, std::placeholders::_1, s));
    std::cout << *it << std::endl;

    std::multiplies<int> intMultipies;

    int m = 2;
    std::transform(std::begin(arr), std::end(arr), std::begin(arr), std::bind(intMultipies, std::placeholders::_1, m));

    for (int* iter = std::begin(arr); iter != std::end(arr); ++iter) {
        std::cout << *iter << " ";
    }

    return 0;
}
