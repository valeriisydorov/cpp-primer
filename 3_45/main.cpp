#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
    constexpr size_t rowSize = 3, colSize = 4;
    const int ia[rowSize][colSize] = {
    {1, 1, 2, 3},
    {5, 8, 13, 21},
    {34, 55, 89, 144}
    };

    for (auto &row: ia) {
        for (auto col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto i = 0; i != rowSize ; ++i) {
        for (auto j = 0; j != colSize ; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}