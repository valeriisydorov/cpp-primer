#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::size;

int main() {
    constexpr size_t rowSize = 3, colSize = 4;
    const int ia[rowSize][colSize] = {
    {1, 1, 2, 3},
    {5, 8, 13, 21},
    {34, 55, 89, 144}
    };

    for (const int (&row)[colSize]: ia) {
        for (const int col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (size_t i = 0; i != rowSize ; ++i) {
        for (size_t j = 0; j != colSize ; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (const int (*p)[colSize] = ia; p != ia + rowSize; ++p) {
        for (const int *q = *p; q != *p + colSize; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}