#include "gameManager.hpp"

#include "rightPanel.hpp"

int GameManager::money = 1000;
int GameManager::turnCounter = 1;

void GameManager::purchaseParts(City* city, int amount) {
    money-=amount*10;
    city->shippingParts+=amount;
    RightPanel::refresh();
}
