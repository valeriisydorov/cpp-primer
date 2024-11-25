#include <iostream>
#include <memory>
#include <string>

int main() {
    size_t n = 5;

    std::allocator<std::string> alloc;
    std::string* p = alloc.allocate(n);

    std::string s;

    std::string* q = p;
    while (std::cin >> s && q != p + n) {
        alloc.construct(q++, s);
    }
    const size_t size = q - p;
    std::cout << size << std::endl;

    while (q != p) {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);

    return 0;
}
