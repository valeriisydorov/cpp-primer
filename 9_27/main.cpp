#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> flst;
    for (int i = 9; i >= 0; --i) {
        flst.push_front(i);
    }
    std::forward_list<int>::iterator prev = flst.before_begin();
    std::forward_list<int>::iterator curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }

    }
    for (int n: flst) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}