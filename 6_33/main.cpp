#include <iostream>
#include <vector>
using std::vector;

void recursiveOutput(vector<int>::iterator v)
{
    if (*v) {
        std::cout << *v << " ";
        return recursiveOutput(++v);
    }
}

int main()
{
    vector<int> v{1, 1, 2, 3, 5, 8, 13, 21};
    recursiveOutput(v.begin());

    return 0;
}