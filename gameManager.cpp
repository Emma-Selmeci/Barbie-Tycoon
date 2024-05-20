#include "gameManager.hpp"

#include <iostream>

#include "rightPanel.hpp"
#include "mainScreen.hpp"
#include "research.hpp"
#include "techTree.hpp"

int GameManager::money = 3000;
int GameManager::turnCounter = 1;
int GameManager::shipmentTime = 3;
int GameManager::eventAccum = 0;
int GameManager::transformationCoefficient = 0;
bool GameManager::cutsceneFlag = false;
bool GameManager::transformationFlag = false;

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

void GameManager::shipDolls(City* from, int toi, int type, int amount) {
    City* to = &City::cities[toi];
    from->shippedThisTurn = true;
    from->storedDolls[type]-=amount;
    switch(shipmentTime) {
        case 3 : {
            to->shippedDolls3[type]+=amount;
            break;
            }
        case 2 : {
            to->shippedDolls2[type]+=amount;
            break;
            }
        case 1 : {
            to->shippedDolls1[type]+=amount;
            break;
            }
    }
    RightPanel::refresh();
}

void GameManager::nextTurn() {
    std::cout << "\n\nTurn " << turnCounter << '\n';
    MainScreen::loadFlag = true;
    turnCounter++;
    for(int i = 0; i < 10; i++) {
        City& c = City::cities[i];
        c.storedParts += c.shippingParts;
        c.shippingParts = 0;
        c.storedDolls[c.producedType] += c.producingDolls;
        c.producingDolls = 0;
        c.shippedThisTurn = false;
        if(c.hasStrike) {
            if(rand() % 4 == 0) c.hasStrike = false;
        }
        if(c.hasFactory) money-=c.wages;
        ship(c);
        if(c.hasLab && !(Research::isItOurCurrentTech() && Research::currentTech->researchAccum > 100)) Research::currentTech->researchAccum+=20;
    }
    if(Research::isItOurCurrentTech() && Research::currentTech->researchAccum > 100) eventAccum++;
    if(eventAccum > 3) cutsceneFlag = true;
    Research::checkUnlock();

    if(transformationFlag) transformationCoefficient++;

    MainScreen::object->quickRepaint();

    generateFans();
    generateStrike();
    RightPanel::refresh();
    TechTree::draw();
}

void GameManager::generateFans() {
    static bool wasInitialized = false;
    if(!wasInitialized) { //I know I can shuffle but I'll do this instead
        int temp[10];
        for(int i = 0; i < 10; i++) temp[i] = i;
        for(int i = 0; i < 10; i++) {
            int a, b, c;
            a = rand() % 10;
            b = rand() % 10;
            c = temp[a];
            temp[a] = temp[b];
            temp[b] = c;
        }
        for(int i = 0; i < 10; i++) {
                fanCities[i] = temp[i];
        }
        wasInitialized = true;
    }

    int turnCoefficient = turnCounter / 10 + 1;
    if(turnCoefficient > 9) turnCoefficient = 9;

    int max = 0;
    if(Research::wasResearched(ResearchEnum::DOLL2)) max = 1;
    if(Research::wasResearched(ResearchEnum::DOLL3)) max = 2;
    if(Research::wasResearched(ResearchEnum::DOLL4)) max = 3;
    if(Research::wasResearched(ResearchEnum::DOLL5)) max = 4;

    for(int i = 0; i < turnCoefficient; i++) {
        int delta = turnCounter/3 + rand() % turnCounter/3 + 5;
        int fanIndex = rand() % (max+1);
        City::cities[fanCities[i]].fans[fanIndex] += (delta + City::cities[fanCities[i]].marketingBonus);
    }

    for(int i = 0; i < 3; i++) {
            int cityId = rand() % 10;
            City::cities[fanCities[cityId]].fans[rand() % (max+1)] += (rand() % turnCounter/5 + City::cities[cityId].marketingBonus);
    }
}

void GameManager::ship(City& city) {
    std::cout << "\n\nShippings for " << city.getName() << '\n';
    std::cout << "Fans : ";
    for(int j = 0; j < 5; j++) std::cout << city.fans[j] << ' ';
    std::cout << "\nArriving this turn : ";
    for(int j = 0; j < 5; j++) std::cout << city.shippedDolls1[j] << ' ';
    std::cout << "\nArriving next turn : ";
    for(int j = 0; j < 5; j++) std::cout << city.shippedDolls2[j] << ' ';
    std::cout << "\nArriving next next turn : ";
    for(int j = 0; j < 5; j++) std::cout << city.shippedDolls3[j] << ' ';

    for(int i = 0; i < 5; i++) {
        if(city.fans[i] > 0) {
                int delta = city.fans[i] > city.shippedDolls1[i] ? city.shippedDolls1[i] : city.fans[i];
                if(delta != 0) std::cout << "\nSelling " << delta << " dolls in " << city.getName() << " for " << delta*StaticData::dollToPrice(i) << '\n';
                money+= delta*StaticData::dollToPrice(i)*(1 + city.shopLevel*0.5);
                city.fans[i]-=delta;
                city.shippedDolls1[i]-=delta;
        }
        city.shippedDolls1[i] = city.shippedDolls2[i];
        city.shippedDolls2[i] = city.shippedDolls3[i];
        city.shippedDolls3[i] = 0;
    }
}

void GameManager::generateStrike() {
    if(turnCounter < 10) return;
    int strikeNum = rand() % 20;
    if(strikeNum > 9) return;
    else if(City::cities[strikeNum].hasFactory) City::cities[strikeNum].hasStrike = true;
}

int GameManager::fanCities[10];

void GameManager::increaseWages(City* city) {
    city->wages+=40;
    city->hasStrike = false;
    RightPanel::refresh();
}

void GameManager::requestRefresh() {
    RightPanel::refresh();
}

void GameManager::changeActiveTech(int techNum) {
    Research::currentTech = &Research::techList[techNum];
}

void GameManager::buildLab(City* city) {
    city->hasLab = true;
    RightPanel::refresh();
}

void GameManager::buildShop(City* city) {
    if(city->shopLevel = 0) {
        city->shopLevel = 1;
        money-=500;
    } else {
        city->shopLevel = 2;
        money-=5000;
    }

    RightPanel::refresh();
}

void GameManager::forceStrike(City* city) {
    city->hasStrike = true;
    RightPanel::refresh();
}

void GameManager::decreaseShipmentTime() {
    shipmentTime--;
    RightPanel::refresh();
}

void GameManager::doMarketing(City* city) {
    city->marketingBonus+=10;
    money-=2000;
}

void GameManager::buildFactory(City* city) {
    city->hasFactory = true;
    money-=500;
    RightPanel::refresh();
}

void GameManager::buildLabAndPay(City* city) {
    city->hasLab = true;
    money-=2000;
    RightPanel::refresh();
}

void GameManager::unlock() {
    Research::unlock();
    RightPanel::refresh();
}

void GameManager::startTransformation() {
    transformationFlag = true;
}
