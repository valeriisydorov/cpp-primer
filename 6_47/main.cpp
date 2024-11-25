#include <iostream>
#include <vector>
using std::vector;

void recursiveOutput(const vector<int>& v)
{
    if (v.begin() != v.end()) {
        std::cout << *v.begin() << " ";
        #ifndef NDEBUG
        std::cerr << v.size() << std::endl;
        #endif
        return recursiveOutput(vector<int>(v.begin() + 1, v.end()));
    }
}

int main()
{
    vector<int> v{1, 1, 2, 3, 5, 8, 13, 21};
    recursiveOutput(v);

    return 0;
}