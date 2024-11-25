#include <iostream>
#include <vector>

int main() {
    std::vector<int> vi{0, 1, 1, 2, 3, 5, 8, 13, 21};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            ++iter; // it fixes an infinity loop
        }
        ++iter;
    }
    for (int& i: vi) {
        std::cout << i << " ";
    }

    return 0;
}
