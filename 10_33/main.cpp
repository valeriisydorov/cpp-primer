#include <fstream>
#include <iterator>
#include <algorithm>

int main() {
    std::ifstream ifs("../Z");
    std::ofstream ofs_even("../even"), ofs_odd("../odd");
    std::istream_iterator<int> in(ifs), eof;
    std::ostream_iterator<int> os_even(ofs_even, "\n"), os_odd(ofs_odd, " ");

    std::for_each(in, eof, [&os_even, &os_odd] (int i) -> void { (i % 2) ? os_odd = i : os_even = i; });

    return 0;
}
