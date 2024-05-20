#include "workerPanel.hpp"

#include "gameManager.hpp"
#include "mainScreen.hpp"
#include "research.hpp"

WorkerPanel::WorkerPanel() :
        status({pos.x+5,pos.y+5},"The workers in this city are content with their 100$ wages"),
        fanWidget({pos.x+5,pos.y+110},"Nobody wants your dolls in this city"),
        increasePayment({pos.x+MainScreen::rightWidth/2,pos.y+70},0,buttonCB,"Raise wages"),
        marketingWidget({pos.x+5,pos.y+160},"Pay 500$ to advetise your products for more demand"),
        marketingButton({pos.x+MainScreen::rightWidth/2,pos.y+200},1,buttonCB,"Advertise")
{
    increasePayment.isActive = false;
    marketingButton.isActive = false;
    addWidget(&status);
    addWidget(&increasePayment);
    addWidget(&fanWidget);
    addWidget(&marketingWidget);
    addWidget(&marketingButton);
}

void WorkerPanel::refresh(City* city) {
    SubPanel::refresh(city);
    std::string t;
    if(!city->hasFactory) {
        increasePayment.isActive = false;
        t = "You have no factory in this city";
        status.updateMessage(t);
    }
    if(!city->hasStrike) {
        increasePayment.isActive = false;
        t = "The workers in this city are content with their " + std::to_string(city->wages) + "$ wages";
        status.updateMessage(t);
    } else {
        increasePayment.isActive = true;
        t = "The workers strike in this city! Will you pay them more?";
        status.updateMessage(t);
    }

    t = "Fans in this city want ";
    bool doWeHave = false;
    for(int i = 0; i < 5; i++) {
        if(city->fans[i] > 0) {
            doWeHave = true;
            t+= std::to_string(city->fans[i]) + " " + StaticData::dollToName(i) + ", ";
        }
    }
    if(!doWeHave) t = "Nobody wants your dolls in this city";

    fanWidget.updateMessage(t);

    marketingButton.isActive = false;
    marketingWidget.isActive = false;

    if(Research::wasResearched(ResearchEnum::MARKETING)) {
        marketingWidget.isActive = true;
        if(GameManager::money >= 500) {
            marketingButton.isActive = true;
        }
    }
}

void WorkerPanel::buttonCB(int i) {
    if(i == 0) {
        GameManager::increaseWages(currentCity);
    } else {
        GameManager::doMarketing(currentCity);
    }

}

void WorkerPanel::update(event& ev) {
    SubPanel::update(ev);
}

void WorkerPanel::draw() {
    SubPanel::draw();
}
