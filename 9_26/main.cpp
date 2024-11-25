#include <iostream>
#include <vector>
#include <list>

int main() {
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    std::vector<int> v;
    std::list<int> l;

    for (int* it = std::begin(a); it != std::end(a); ++it) {
        v.push_back(*it);
        l.push_back(*it);
    }

    std::vector<int>::iterator iv = v.begin();
    std::list<int>::iterator il = l.begin();
    while (iv != v.end()) {
        if (*iv % 2) {
            il = l.erase(il);
            ++iv;
        } else {
            iv = v.erase(iv);
            ++il;
        }
    }

    for (int el: v) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    for (int el: l) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}
