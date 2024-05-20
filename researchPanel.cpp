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
    shopButton({pos.x+MainScreen::rightWidth/2,pos.y+200},1,buttonCB,"Upgrade commerce"),
    labWidget({pos.x+5,pos.y+240},""),
    labButton({pos.x+MainScreen::rightWidth/2,pos.y+320},2,buttonCB,"Upgrade research")
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

    t = GameManager::transformationCoefficient > 5 ? "This library has a strange door in its basement..." : "This lab has a strange door in its basement...";
    budapestWidget.updateMessage(t);

    if(city->hasLab) {
        t = GameManager::transformationCoefficient > 5 ? "You have an occult library here" : "You have a working lab in this city";
    } else {
        t = GameManager::transformationCoefficient > 5 ? "You have no occult library here" : "You have no lab in this city";
    }

    if(specialEvent) {
        budapestWidget.isActive = false;
        enterButton.isActive = false;
        t = GameManager::transformationCoefficient > 2 ? "*You enter a darkly lit chamber where a dark ritual has taken place. Human bodies lie scattered in the room. You recognize some of them*" : "It's locked";
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
            t = GameManager::transformationCoefficient > 14 ? "Your dark basilica attracts twice as many followers" : "Your Mojo Dojo Casa House provides 2x profits in this city";
        } else if(city->shopLevel == 1) {
            if(Research::wasResearched(ResearchEnum::MOJODOJO)) {
                t = GameManager::transformationCoefficient > 14 ? "Your dark temple attracts 1.5 times as many followers, but you could update it further for 5000 souls" : "Your shop provides 1.5x profits in this city, but you could update it for $5000";
                if(GameManager::money >= 5000) shopButton.isActive = true;
            } else {
                t = GameManager::transformationCoefficient > 14 ? "Your dark temple attracts 1.5 times as many followers" : "Your shop provides 1.5x profits in this city";
            }

        } else if(city->shopLevel == 0) {
            t = GameManager::transformationCoefficient > 14 ? "Your can erect a dark temple here for $500" :  "You can build a shop here for $1000";
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
        t = GameManager::transformationCoefficient > 2 ? "You can create an occult library here for 2000 souls" : "You can build a lab here for $2000";
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
