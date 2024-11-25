#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main() {
    std::istream_iterator<int> in(std::cin), eof;
    std::ostream_iterator<int> out(std::cout, " ");
    std::vector<int> iv, siv;

    while (in != eof) {
        iv.push_back(*in);
        in++;
    }

    std::sort(iv.begin(), iv.end());
    std::unique_copy(iv.begin(), iv.end(), std::back_inserter(siv));

    for (int& i: siv) {
        *out = i;
        out++;
    }
    std::cout << std::endl;

    return 0;
}
