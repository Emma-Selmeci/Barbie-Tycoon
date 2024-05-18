#include <iostream>

#include "mainScreen.hpp"
#include "rightPanel.hpp"
#include "gameManager.hpp"
#include "staticData.hpp"

const static int borderSize = 20, decorationSize = 2, screenWidth = 1000, screenHeight = 600, mapWidth = 650, mapHeight = 423, textPanelHeight = 30, remainder = screenHeight-4*borderSize-mapHeight-textPanelHeight, rightHeight = screenHeight-2*borderSize;
int MainScreen::rightWidth = screenWidth-3*borderSize-mapWidth;

MainScreen::MainScreen(event& ev) : mapPanel(borderSize,borderSize*2+textPanelHeight) {
    drawBorders({GUIviolet},{GUIvioletLight},{GUIvioletDark});
    drawBackground({lightPink});
    gout.load_font("classic.ttf",15);
    gout << color(0,0,0);
    drawTitle();
    drawCurrency();

    RightPanel::setDim({borderSize*2+mapWidth,borderSize},{rightWidth,rightHeight});
    MessagePanel::setPos({borderSize,borderSize*2+textPanelHeight},{mapWidth,mapHeight});
    StaticData::leftArrow.setTransparent(false);
    StaticData::rightArrow.setTransparent(false);


    MessagePanel::draw();
    RightPanel::draw();

    gout << refresh;

    eventLoop(ev);
}

void MainScreen::eventLoop(event& ev) {
    loadMessages(ev);
    while(gin >> ev) {
            if(ev.type == ev_timer) {
                drawCurrency();
                RightPanel::draw(); //We're calling this last due to font changes!
                gout << refresh;
            } else {
                mapPanel.update(ev);
                RightPanel::update(ev);
            }
    }
}

void MainScreen::loadMessages(event& ev) {
    MessagePanel::loadMessages(ev);
    mapPanel.draw();
    gout << refresh;
}

void MainScreen::drawBorders(Color foreground, Color light, Color dark) { //Let's pretend we didn't see this
    drawRect({0,0},{screenWidth,screenHeight},{foreground});

    drawRect({0,0},{screenWidth,decorationSize},{light});
    drawRect({0,0},{decorationSize,screenHeight-decorationSize});

    drawRect({borderSize-decorationSize,borderSize+textPanelHeight},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize+mapWidth,borderSize},{decorationSize,textPanelHeight});

    drawRect({borderSize-decorationSize,borderSize*2+textPanelHeight+mapHeight},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize+mapWidth,borderSize*2+textPanelHeight},{decorationSize,mapHeight});

    drawRect({borderSize-decorationSize,borderSize*3+textPanelHeight+mapHeight+remainder},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize+mapWidth,borderSize*3+textPanelHeight+mapHeight},{decorationSize,remainder});

    drawRect({borderSize*2+mapWidth-decorationSize,borderSize*3+textPanelHeight+mapHeight+remainder},{rightWidth+decorationSize*2,decorationSize});
    drawRect({screenWidth-borderSize,borderSize},{decorationSize,rightHeight});

    drawRect({screenWidth-decorationSize,decorationSize},{decorationSize,screenHeight-decorationSize},{dark});
    drawRect({0,screenHeight-decorationSize},{screenWidth,decorationSize});

    drawRect({borderSize-decorationSize,borderSize-decorationSize},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize-decorationSize,borderSize-decorationSize},{decorationSize,textPanelHeight+decorationSize});

    drawRect({borderSize-decorationSize,borderSize*2+textPanelHeight-decorationSize},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize-decorationSize,borderSize*2+textPanelHeight-decorationSize},{decorationSize,mapHeight+decorationSize});

    drawRect({borderSize-decorationSize,borderSize*3+textPanelHeight+mapHeight-decorationSize},{mapWidth+decorationSize*2,decorationSize});
    drawRect({borderSize-decorationSize,borderSize*3+textPanelHeight+mapHeight-decorationSize},{decorationSize,remainder+decorationSize});

    drawRect({borderSize*2+mapWidth-decorationSize,borderSize-decorationSize},{rightWidth+decorationSize*2,decorationSize});
    drawRect({borderSize*2+mapWidth-decorationSize,borderSize-decorationSize},{decorationSize,rightHeight+decorationSize});

}

void MainScreen::drawBackground(Color color) {
    drawRect({borderSize,borderSize},{mapWidth,textPanelHeight},{color});
    drawRect({borderSize,borderSize*2+textPanelHeight},{mapWidth,mapHeight});
    drawRect({borderSize,borderSize*3+textPanelHeight+mapHeight},{mapWidth,remainder});
    drawRect({borderSize*2+mapWidth,borderSize},{rightWidth,rightHeight});
}

void MainScreen::drawTitle() {
    gout << move_to(borderSize+5,borderSize+8) << text("BARBIE TYCOON");
}

void MainScreen::drawCurrency() {
    drawRect({borderSize+5+mapWidth/2,borderSize},{mapWidth/2,textPanelHeight},{lightPink});
    std::string moneyMessage = "You have " + std::to_string(GameManager::money) + "$";
    gout << color(0,0,0) << move_to(borderSize+5+mapWidth/2,borderSize+8) << text(moneyMessage);
}
