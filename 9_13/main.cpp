#include <vector>
#include <list>

int main() {
    std::list<int> li{1, 2, 3};
    std::vector<int> vi{1, 2, 3};
    std::vector<double> vd1(li.begin(),li.end());
    std::vector<double> vd2(vi.begin(),vi.end());

    return 0;
}
