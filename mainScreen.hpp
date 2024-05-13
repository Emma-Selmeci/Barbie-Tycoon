#ifndef MAINSCREEN.HPP
#define MAINSCREEN.HPP

#include "graphics.hpp"

#include "mapPanel.hpp"
#include "colors.hpp"
#include "graphicsHelper.hpp"

using namespace genv;

class MainScreen {
    //MapPanel mapPanel;
    void eventLoop(event&);
    void drawBorders(Color foreground, Color light, Color dark);

public:
    MainScreen(event&);
};

#endif // MAINSCREEN
