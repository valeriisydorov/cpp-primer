#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> seq;
    for (int i = 1; i != 10; ++i) {
        seq.push_back(i * i);
    }

    std::cout << "The full sequence: ";
    for (int& n: seq) {
        std::cout << n << " ";
    }
    std::cout << '\n';

    std::fill_n(seq.begin(), seq.size(), 0);

    std::cout << "The zero sequence: ";
    for (int& n: seq) {
        std::cout << n << " ";
    }
    std::cout << '\n';

    return 0;
}
