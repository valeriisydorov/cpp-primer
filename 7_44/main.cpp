#include<vector>

class NoDefault {
public:
    NoDefault(int x): val(x) {};
private:
    int val;
};

int main() {
    std::vector<NoDefault> vec(10);

    return 0;
}