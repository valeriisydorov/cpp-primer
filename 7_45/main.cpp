#include <vector>

class NoDefault {
public:
    NoDefault(int x): val(x) {};
private:
    int val;
};

class C {
public:
    C() = default;
private:
    NoDefault obj;
};

int main() {
    std::vector<C> vec(10);

    return 0;
}
