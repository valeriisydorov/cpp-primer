#include <string>
using std::string;

using strArr = string[10];
strArr* func1();

auto func2() -> string(*)[10];

string arr[10];
decltype(arr) *func3();

int main() {
    return 0;
}
