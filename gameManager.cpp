#include "gameManager.hpp"

#include "rightPanel.hpp"
#include "mainScreen.hpp"

int GameManager::money = 1000;
int GameManager::turnCounter = 1;

void GameManager::purchaseParts(City* city, int amount) {
    money-=amount*10;
    city->shippingParts+=amount;
    RightPanel::refresh();
}

void GameManager::produceDolls(City* city, int type, int amount) {

    city->producingDolls = amount;
    city->producedType = type;
    city->storedParts-= StaticData::dollToParts(type)*amount;
    RightPanel::refresh();
}

void GameManager::nextTurn() {
    MainScreen::loadFlag = true;
    turnCounter++;
    for(int i = 0; i < 10; i++) {
        City& c = City::cities[i];
        c.storedParts = c.shippingParts;
        c.shippingParts = 0;
        c.storedDolls[c.producedType] += c.producingDolls;
        c.producingDolls = 0;
    }
    RightPanel::refresh();
}

void GameManager::requestRefresh() {
    RightPanel::refresh();
}
