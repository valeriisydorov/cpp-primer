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

    using rowArr = const int[colSize];
    using colElem = const int;
    using arrSize = size_t;

    for (rowArr &row: ia) {
        for (colElem col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (arrSize i = 0; i != rowSize ; ++i) {
        for (arrSize j = 0; j != colSize ; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (rowArr *p = begin(ia); p != end(ia); ++p) {
        for (colElem *q = begin(*p); q != end(*p); ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}