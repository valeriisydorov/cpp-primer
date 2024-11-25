#ifndef SCREENTEMPLATE_H
#define SCREENTEMPLATE_H


#include <iostream>
#include <cstddef>
#include <string>


template <typename T> class Screen {
    friend std::istream& operator>>(std::istream& is, Screen<T>& screen) {
        is >> screen.cursor >> screen.height >> screen.width >> screen.contents;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Screen<T>& screen) {
        screen.doDisplay(os);
        return os;
    }
public:
    Screen() = default;
    Screen(T ht, T wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(T ht, T wd, char c): height(ht), width(wd), contents(ht * wd, c) { }

    char get() const { return contents[cursor]; }
    inline char get(T, T) const;
    Screen& move(T, T);
    void someMember() const;
    Screen& set(char);
    Screen& set(T, T, char);
    Screen& display(std::ostream& os) {
        doDisplay(os);
        return *this;
    }
    const Screen& display(std::ostream& os) const {
        doDisplay(os);
        return *this;
    }
private:
    T cursor = 0;
    T height = 0;
    T width = 0;
    std::string contents;
    mutable size_t accessCtr;

    void doDisplay(std::ostream& os) const {
        for (T i = 0; i < height; ++i) {
            os << contents.substr(i * width, width) << '\n';
        }
    }
};

template <typename T> inline Screen<T>& Screen<T>::move(T r, T c) {
    T row = r * width;
    cursor = row + c;
    return *this;
}

template <typename T> inline char Screen<T>::get(T r, T c) const {
    T row = r * width;
    return contents[row + c];
}

template <typename T> void Screen<T>::someMember() const {
    ++accessCtr;
}

template <typename T> inline Screen<T>& Screen<T>::set(char c) {
    contents[cursor] = c;
    return *this;
}

template <typename T> inline Screen<T>& Screen<T>::set(T r, T col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}


#endif
