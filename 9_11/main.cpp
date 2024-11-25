#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> v1{1, 1, 2, 3, 5, 8, 13};
    vector<int> v2 = {1, 2, 3, 5, 7, 11, 13};
    vector<int> v3(v1);
    vector<int> v4 = v2;
    vector<int> v5(v3.begin() + 2, --v3.end());
    vector<int> v6(7);
    vector<int> v7(3, 17);

    vector<vector<int>> pack{v1, v2, v3, v4, v5, v6, v7};

    for (vector<int> packElem: pack) {
        for (int elem: packElem) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
