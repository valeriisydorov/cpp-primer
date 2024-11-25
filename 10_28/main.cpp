#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;

int main() {
    vector<int> numbers;
    for (int i = 1; i != 10; ++i) {
        numbers.push_back(i);
    }

    vector<int> numbers1, numbers2, numbers3;

    std::copy(numbers.begin(), numbers.end(), std::inserter(numbers1, numbers1.begin()));
    std::for_each(numbers1.begin(), numbers1.end(), [] (int i) -> void {
        std::cout << i << " ";
    });
    std::cout << "\n";

    std::copy(numbers.begin(), numbers.end(), std::back_inserter(numbers2));
    std::for_each(numbers2.begin(), numbers2.end(), [] (int i) -> void {
        std::cout << i << " ";
    });
    std::cout << "\n";

//    std::copy(numbers.begin(), numbers.end(), std::front_inserter(numbers3));
//    std::for_each(numbers3.begin(), numbers3.end(), [] (int i) -> void {
//        std::cout << i << " ";
//    });
//    std::cout << "\n";

    return 0;
}
