#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> seq;
    for (int i = 0; i != 100; ++i) {
        seq.push_back(i);
    }
    int sum = std::accumulate(seq.cbegin(), seq.cend(), *seq.cbegin());
    std::cout << sum << "\n";

    return 0;
}
