#include "Window_mgr.h"
#include "Screen.h"

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

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;

    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;

    return *this;
}