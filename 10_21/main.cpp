int main() {
    int i = 0;

    auto f = [i] () mutable -> bool {
        bool isZero = i == 0;
        while (i != 0) {
            --i;
        }
        return isZero;
    };

    bool j = f();

    return 0;
}
