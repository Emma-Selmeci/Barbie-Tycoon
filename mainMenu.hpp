#ifndef MAINMENU.HPP
#define MAINMENU.HPP

#include "graphics.hpp"

#include "imageLoader.hpp"

using namespace genv;

class MainMenu {
private:
    ImageLoader background, barbieHead;
    void eventLoop(event&);
    void reDraw();
    short int state = -1;
public:
    MainMenu(event&);
    friend class MainScreen;
};

#endif // MAINMENU
