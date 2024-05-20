#include "researchPanel.hpp"

#include <iostream>

#include "gameManager.hpp"
#include "mainScreen.hpp"
#include "research.hpp"

bool ResearchPanel::specialEvent = false;

ResearchPanel::ResearchPanel() :
    statusWidget({pos.x+5,pos.y+5},"You have no lab in this city"),
    budapestWidget({pos.x+5,pos.y+45},"This lab has a strange door in its basement..."),
    enterButton({pos.x+MainScreen::rightWidth/2,pos.y+100},0,buttonCB,"Open door"),
    shopWidget({pos.x+5,pos.y+150},""),
    shopButton({pos.x+MainScreen::rightWidth/2,pos.y+200},1,buttonCB,"Build shop"),
    labWidget({pos.x+5,pos.y+240},""),
    labButton({pos.x+MainScreen::rightWidth/2,pos.y+320},2,buttonCB,"Build lab")
{
    budapestWidget.isActive = false;
    enterButton.isActive = false;
    labButton.isActive = false;
    addWidget(&statusWidget);
    addWidget(&budapestWidget);
    addWidget(&enterButton);
    addWidget(&shopWidget);
    addWidget(&shopButton);
    addWidget(&labWidget);
    addWidget(&labButton);
}

void ResearchPanel::refresh(City* city) {
    SubPanel::refresh(city);
    std::string t,s;
    s = "Budapest";

    if(city->hasLab) {
        t = "You have a working lab in this city";
    } else {
        t = "You have no lab in this city";
    }

    if(specialEvent) {
        budapestWidget.isActive = false;
        enterButton.isActive = false;
        t = "It's locked";
        specialEvent = false;
        statusWidget.updateMessage(t);
    } else if(city->getName() == s && city->hasLab) {
        budapestWidget.isActive = true;
        enterButton.isActive = true;
    } else {
        budapestWidget.isActive = false;
        enterButton.isActive = false;
    }

    statusWidget.updateMessage(t);

    shopWidget.isActive = false;
    shopButton.isActive = false;

    if(Research::wasResearched(ResearchEnum::SHOP)) {
        if(city->shopLevel == 2) {
            t = "Your Mojo Dojo Casa House provides 2x profits in this city";
        } else if(city->shopLevel == 1) {
            if(Research::wasResearched(ResearchEnum::MOJODOJO)) {
                t = "Your shop provides 1.5x profits in this city, but you could update it for $5000";
                if(GameManager::money >= 5000) shopButton.isActive = true;
            } else {
                t = "Your shop provides 1.5x profits in this city";
            }

        } else if(city->shopLevel == 0) {
            t = "You can build a shop here for $1000";
            if(GameManager::money >= 1000) {
                shopButton.isActive = true;
            }
        }
        shopWidget.isActive = true;
        shopWidget.updateMessage(t);
    }

    labWidget.isActive = false;
    labButton.isActive = false;

    if(Research::wasResearched(ResearchEnum::MORERESEARCH)) {
        t = "You can build a lab here for $2000";
        labWidget.isActive = false;
        labWidget.updateMessage(t);
        if(GameManager::money >= 2000) {
            labButton.isActive = true;

        }
    }
}

void ResearchPanel::buttonCB(int i) {
    if(i == 0) {
        specialEvent = true;
        GameManager::requestRefresh();
    } else if(i == 1) {
        GameManager::buildShop(currentCity);
    } else if(i == 2) {
        GameManager::buildLabAndPay(currentCity);
    }

}

void ResearchPanel::draw() {
    SubPanel::draw();
}

void ResearchPanel::update(event& ev) {
    SubPanel::update(ev);
}
