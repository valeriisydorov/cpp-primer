#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include "Window_mgr.h"
#include "Screen.h"

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    const Screen blank(5, 3);
    myScreen.display(cout);
    cout << "\n";

    return 0;
}