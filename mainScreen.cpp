#include "mainScreen.hpp"

const static int borderSize = 20, decorationSize = 2, screenWidth = 1000, screenHeight = 600, mapWidth = 650, mapHeight = 423, textPanelHeight = 30, remainder = screenHeight-4*borderSize-mapHeight-textPanelHeight, rightWidth = screenWidth-3*borderSize-mapWidth, rightHeight = screenHeight-2*borderSize;
//97 pixel(?) az üres terület alul


MainScreen::MainScreen(event& ev) {
    drawBorders({GUIviolet},{GUIvioletLight},{GUIvioletDark});

    drawRect({borderSize,borderSize},{mapWidth,textPanelHeight},{255,255,255});
    drawRect({borderSize,borderSize*2+textPanelHeight},{mapWidth,mapHeight});
    drawRect({borderSize,borderSize*3+textPanelHeight+mapHeight},{mapWidth,remainder});
    drawRect({borderSize*2+mapWidth,borderSize},{rightWidth,rightHeight});

    gout << refresh;

    eventLoop(ev);
}

void MainScreen::eventLoop(event& ev) {
    while(gin >> ev) {

    }
}

void MainScreen::drawBorders(Color foreground, Color light, Color dark) {
    drawRect({0,0},{screenWidth,screenHeight},{foreground});

    drawRect({0,0},{screenWidth,decorationSize},{light});
    drawRect({0,0},{decorationSize,screenHeight-decorationSize});

    drawRect({borderSize-decorationSize,borderSize+textPanelHeight},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize+mapWidth,borderSize},{decorationSize,textPanelHeight});

    drawRect({borderSize-decorationSize,borderSize*2+textPanelHeight+mapHeight},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize+mapWidth,borderSize*2+textPanelHeight},{decorationSize,mapHeight});

    drawRect({borderSize-decorationSize,borderSize*3+textPanelHeight+mapHeight+remainder},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize+mapWidth,borderSize*3+textPanelHeight+mapHeight},{decorationSize,remainder});

}
