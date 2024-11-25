#include <iostream>
#include "Screen.h"


int main()
{
    Screen screen;

    const Screen::pos Screen::*pcur = Screen::cursor_data();

    std::cout << screen.*pcur << std::endl;

    return 0;
}
