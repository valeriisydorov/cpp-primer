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
    C obj;

    return 0;
}
