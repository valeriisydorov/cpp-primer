#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::size;

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    constexpr size_t size1 = size(arr1);
    int *beg1 = arr1;
    int *end1 = arr1 + size1;
    int arr2[] = {1, 2, 3, 4, 5, 6};
    constexpr size_t size2 = size(arr2);
    int *beg2 = arr2;
    int *end2 = arr2 + size2;

    while (beg1 != end1 && beg2 != end2) {
        if (*beg1 != *beg2) {
            if (*beg1 > *beg2) {
                cout << "arr1 is more than arr2";
            } else {
                cout << "arr1 is less than arr2";
            }
            break;
        } else {
            if (beg1 == end1 - 1 && beg2 == end2 - 1) {
                cout << "arr1 and arr2 are equal";
            } else if (beg1 == end1 - 1) {
                cout << "arr1 is less than arr2";
            } else if (beg2 == end2 - 1) {
                cout << "arr1 is more than arr2";
            }
        }
        ++beg1;
        ++beg2;
    }

    cout << endl;

    vector<int> vec1 = {2, 4, 6, 8, 10, 12};
    vector<int> vec2 = {2, 4, 6, 8, 10, 12, 14};

    if (vec1 > vec2) {
        cout << "vec1 is more than vec2";
    } else if (vec1 < vec2) {
        cout << "vec1 is less than vec2";
    } else {
        cout << "vec1 and vec2 are equal";
    }

    return 0;
}