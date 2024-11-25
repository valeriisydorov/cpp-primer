#include <vector>
using std::vector;

int fn(int, int);

int main() {
    vector<decltype(&fn)> v;

    return 0;
}
