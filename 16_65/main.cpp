#include <iostream>
#include <sstream>
#include <string>

template <typename T> std::string debug_rep(const T& t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << "null pointer";
    }
    return ret.str();
}

std::string debug_rep(const std::string& s) {
    return '"' + s + '"';
}

std::string debug_rep(const std::string& s);

template<> std::string debug_rep(char *p) {
    std::cout << "debug_rep(char *p)\n";
    return debug_rep(std::string(p));
}

template<> std::string debug_rep(const char *p) {
    std::cout << "debug_rep(const char *p)\n";
    return debug_rep(std::string(p));
}

int main() {
    std::string s("Hi");
    std::cout << debug_rep(s) << '\n';
    std::cout << debug_rep(&s) << '\n';

    std::cout << debug_rep("Hi") << '\n';

    char arr[] = "Hi";
    char *p = arr;
    
    std::cout << debug_rep(p) << '\n';

    return 0;
}