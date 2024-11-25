#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> m;
    std::map<std::string, std::string>::key_type i = "Hello";
    std::map<std::string, std::string>::mapped_type v = "World";
    m[i] = v;
    std::map<std::string, std::string>::mapped_type ret = m["Hello"];

    return 0;
}
