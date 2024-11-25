#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include <string>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};


#endif
