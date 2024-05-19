#include "productionPanel.hpp"

#include <iostream>

#include "mainScreen.hpp"
#include "staticData.hpp"
#include "gameManager.hpp"

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
    produceButton({pos.x+MainScreen::rightWidth/2,pos.y+320},0,buttonPressed,"Produce dolls!")
    {
    amountSliderP = &amountSlider;
    selectDollP = &selectDoll;
    noFactory.isActive = false;
    orderedDolls.isActive = false;
    addWidget(&selectDoll);
    addWidget(&noFactory);
    addWidget(&chooseWhatToProduce);
    addWidget(&dollPrice);
    addWidget(&amountSlider);
    addWidget(&partsHere);
    addWidget(&orderedDolls);
    addWidget(&produceButton);
}

void ProductionPanel::draw() {
    SubPanel::draw();
}

void ProductionPanel::buttonPressed(int id) {
    GameManager::produceDolls(currentCity,selectDollP->getValue(),amountSliderP->getValue());
}

void ProductionPanel::selectorChange(int val, int id) {
    GameManager::requestRefresh();
}

void ProductionPanel::refresh(City* city) {
    SubPanel::refresh(city);

    if(city->hasFactory) {
        if(city->producingDolls == 0) {
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
    }
    std::cout << selectDoll.getValue() << '\n';
    std::string t = std::to_string(StaticData::dollToParts(selectDoll.getValue())) + " parts to produce one doll. Choose the amount!";
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
