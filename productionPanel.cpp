#include "productionPanel.hpp"

#include <iostream>

#include "mainScreen.hpp"
#include "staticData.hpp"
#include "gameManager.hpp"
#include "research.hpp"

Slider* ProductionPanel::amountSliderP;
Selector* ProductionPanel::selectDollP;

ProductionPanel::ProductionPanel() :
    noFactory({pos.x+5,pos.y+5},"This city has no factory yet! You'll soon be able to build a factory here"),
    chooseWhatToProduce({pos.x+5,pos.y+5},"Choose which doll to produce in this factory!"),
    dollPrice({pos.x+5,pos.y+130},"2 parts to produce one doll. Choose the amount!"),
    amountSlider({pos.x,pos.y+200},0,0),
    partsHere({pos.x+5,pos.y+270},"There are 0 parts here"),
    selectDoll({pos.x+5,pos.y+70},SelectorType::DOLLSELECTOR,selectorChange,0),
    orderedDolls({pos.x+5,pos.y+5},""),
    produceButton({pos.x+MainScreen::rightWidth/2,pos.y+320},0,buttonPressed,"Produce dolls!"),
    buildButton({pos.x+MainScreen::rightWidth/2,pos.y+200},1,buttonPressed,"Build new factory")
    {
    amountSliderP = &amountSlider;
    selectDollP = &selectDoll;
    noFactory.isActive = false;
    orderedDolls.isActive = false;
    buildButton.isActive = false;
    addWidget(&selectDoll);
    addWidget(&noFactory);
    addWidget(&chooseWhatToProduce);
    addWidget(&dollPrice);
    addWidget(&amountSlider);
    addWidget(&partsHere);
    addWidget(&orderedDolls);
    addWidget(&produceButton);
    addWidget(&buildButton);
}

void ProductionPanel::draw() {
    SubPanel::draw();
}

void ProductionPanel::buttonPressed(int id) {
    if(id == 0) {
        GameManager::produceDolls(currentCity,selectDollP->getValue(),amountSliderP->getValue());
    } else {
        GameManager::buildFactory(currentCity);
    }

}

void ProductionPanel::selectorChange(int val, int id) {
    GameManager::requestRefresh();
}

void ProductionPanel::refresh(City* city) {
    SubPanel::refresh(city);
    std::string t;
    if(city->hasFactory) {
        if(city->hasStrike) {
            for(int i = 0; i < widgets.size(); i++) if(widgets[i] != &noFactory) widgets[i]->isActive = false; else widgets[i]->isActive = true;
            t= "Workers are on strike! You cannot produce anything until they stop";
            noFactory.updateMessage(t);
            }
        else if(city->producingDolls == 0) {
            for(int i = 0; i < widgets.size(); i++) {
            if(widgets[i] != &noFactory && widgets[i] != &orderedDolls) widgets[i]->isActive = true; else widgets[i]->isActive = false;
            }

        } else {
            for(int i = 0; i < widgets.size(); i++) {
            if(widgets[i] == &orderedDolls) widgets[i]->isActive = true; else widgets[i]->isActive = false;
            }
        }

    } else {
        for(int i = 0; i < widgets.size(); i++) {
            if(widgets[i] != &noFactory) widgets[i]->isActive = false; else widgets[i]->isActive = true;
        }
        if(Research::wasResearched(ResearchEnum::MOREFACTORIES)) {
            t = "You can build a factory here for $2000";
        } else {
            t = "This city has no factory yet! You'll soon be able to build a factory here";
        }

        noFactory.updateMessage(t);
    }

    if(Research::wasResearched(ResearchEnum::MOREFACTORIES) && GameManager::money > 2000 && !city->hasFactory) {
        buildButton.isActive = true;
    } else {
        buildButton.isActive = false;
    }

    t = std::to_string(StaticData::dollToParts(selectDoll.getValue())) + " parts to produce one doll. Choose the amount!";
    dollPrice.updateMessage(t);
    t = "There are " + std::to_string(city->storedParts) + " parts here";
    partsHere.updateMessage(t);
    amountSlider.resetValues(0,city->storedParts/StaticData::dollToParts(selectDoll.getValue()));
    t = "Our workers will produce " + std::to_string(city->producingDolls) + " " + StaticData::dollToName(city->producedType) + " this turn";
    orderedDolls.updateMessage(t);
}


void ProductionPanel::update(event& ev) {
SubPanel::update(ev);
}
