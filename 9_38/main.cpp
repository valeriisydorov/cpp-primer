#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> vec;
    vector<vector<int>::size_type> every{vec.size(), vec.capacity()};
    vector<vector<vector<int>::size_type>> total;
    total.push_back(every);

    vector<int>::size_type currentCapacity = vec.capacity();
    for (vector<int>::size_type i = 0; i != 1000; ++i) {
        vec.push_back(i);
        if (currentCapacity < vec.capacity()) {
            every = {vec.size(), vec.capacity()};
            total.push_back(every);
            currentCapacity = vec.capacity();
        }
    }

    for (vector<vector<int>::size_type>& ev: total) {
        for (vector<int>::size_type& val: ev) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}