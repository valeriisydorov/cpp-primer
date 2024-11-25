#include <iostream>
#include <list>
#include <forward_list>

int main()
{
    std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin();
    while (iter != li.end()) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter);
            ++iter;
            ++iter;
        } else {
            iter = li.erase(iter);
        }
    }
    for (int n: li) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = fli.begin();
    auto before = fli.before_begin();
    while (begin != fli.end()) {
        if (*begin % 2) {
            begin = fli.insert_after(begin, *begin);
            ++begin;
        } else {
            begin = fli.erase_after(before);
        }
        ++before;
    }
    for (int n: fli) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}