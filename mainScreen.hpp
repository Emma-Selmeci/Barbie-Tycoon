#ifndef MAINSCREEN.HPP
#define MAINSCREEN.HPP

#include "graphics.hpp"

#include "mapPanel.hpp"
#include "colors.hpp"
#include "graphicsHelper.hpp"
#include "messagePanel.hpp"

using namespace genv;

class MainScreen {
    void eventLoop(event&);
    void drawBorders(Color foreground, Color light, Color dark);
    void drawBackground(Color);
    void drawTitle();
    void drawCurrency();
    void loadMessages(event&);
    MapPanel mapPanel;

public:
    MainScreen(event&);
    static int rightWidth;
};

#endif // MAINSCREEN
