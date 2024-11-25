#pragma once


#include <string>


class Screen
{
public:
    typedef std::string::size_type pos;

    char get_cursor() const
    {
        return contents[cursor];
    }
    char get() const;
    char get(pos ht, pos wd);
    static const pos Screen::*cursor_data()
    {
        return &Screen::cursor;
    }

private:
    std::string contents;
    pos cursor = 42;
    pos height, width;

};