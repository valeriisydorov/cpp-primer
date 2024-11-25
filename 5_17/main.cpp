#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> a = {1, 1, 2, 3, 5}, b = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int>::size_type prefixSize = a.size();
    if (a.size() > b.size()) {
        prefixSize = b.size();
    }

    bool isPrefix = true;
    for (int i = 0; i != prefixSize; ++i) {
        if (a[i] - b[i]) {
            isPrefix = false;
        }
    }

    std::cout << std::boolalpha << isPrefix;

    return 0;
}
