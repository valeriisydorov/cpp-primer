#include <iostream>
#include <map>
#include <string>
#include <functional>

int main(int argc, char* argv[]) {
    std::map<std::string, std::function<int(int, int)>> simpleCalc;
    simpleCalc.insert({"+", std::plus<int>()});
    simpleCalc.insert({"-", std::minus<int>()});
    simpleCalc.insert({"*", std::multiplies<int>()});
    simpleCalc.insert({"/", std::divides<int>()});
    simpleCalc.insert({"%", std::modulus<int>()});

    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[3]);
    std::string op = argv[2];

    std::function<int(int, int)> operation = simpleCalc[op];

    std::cout << operation(a, b) << std::endl;

    return 0;
}