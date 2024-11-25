#pragma once


#include <string>


class Screen
{
public:
    enum Directions {
        HOME,
        FORWARD,
        BACK,
        UP,
        DOWN
    };

    using pos = std::string::size_type;
    using Action = Screen& (Screen::*)();
    using Movement = Screen& (Screen::*)(Directions);
    using Cursor_Postion = char (Screen::*)() const;
    using Postion = char (Screen::*)(pos, pos) const;

    Screen& move(Directions);
    Screen& home();
    Screen& forward();
    Screen& back();
    Screen& up();
    Screen& down();

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
    pos cursor;
    pos height, width;

};