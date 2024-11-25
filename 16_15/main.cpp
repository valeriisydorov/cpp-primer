#include "ScreenTemplate.h"


int main() {
    Screen<int> myScreen(3, 9, '*');
    myScreen.move(1, 4).set('X');
    std::cout << myScreen << std::endl;

    return 0;
}
