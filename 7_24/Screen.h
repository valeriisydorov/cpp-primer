#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
public:
    using pos = std::string::size_type;
//    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    char get() const
    {
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;
    
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    mutable size_t access_ctr;
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;

    return *this;
}

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;

    return contents[row + c];
}

void Screen::some_member() const
{
    ++access_ctr;
}

#endif
