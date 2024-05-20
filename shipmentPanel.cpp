#include "shipmentPanel.hpp"

#include "gameManager.hpp"
#include "mainScreen.hpp"
#include "staticData.hpp"

Selector* ShipmentPanel::selectDollP;
Selector* ShipmentPanel::selectCityP;
Slider* ShipmentPanel::amountSliderP;

ShipmentPanel::ShipmentPanel() :
    dollsHere({pos.x+5,pos.y+5},"You have no dolls stored here"),
    whereToShip({pos.x+5,pos.y+170},"Choose which type of doll to ship and to where!"),
    selectDoll({pos.x,pos.y+230},SelectorType::DOLLSELECTOR,selectorCB,0),
    selectCity({pos.x,pos.y+270},SelectorType::CITYSELECTOR,selectorCB,0),
    amountSlider({pos.x,pos.y+320},0,0),
    statusText({pos.x+5,pos.y+380},""),
    confirmButton({pos.x+MainScreen::rightWidth/2,pos.y+450},0,buttonCB,"Confirm shipment")
{
    selectDollP = &selectDoll;
    selectCityP = &selectCity;
    amountSliderP = &amountSlider;
    addWidget(&dollsHere);
    addWidget(&whereToShip);
    addWidget(&selectDoll);
    addWidget(&selectCity);
    addWidget(&amountSlider);
    addWidget(&statusText);
    addWidget(&confirmButton);
            for(int i = 0; i < 7; i++) {
            if(widgets[i] != &dollsHere) widgets[i]->isActive = false; else widgets[i]->isActive = true;
        }
}

void ShipmentPanel::refresh(City* city) {
    SubPanel::refresh(city);
    std::string t;

    t = GameManager::transformationCoefficient > 15 ? "Choose where your minions will be deployed" : "Choose which type of doll to ship and to where!";

    t = "You have ";
    bool doWeHave = false;
    for(int i = 0; i < 5; i++) {
        if(city->storedDolls[i] > 0) {
                doWeHave = true;
            t+= std::to_string(city->storedDolls[i]) + " " + StaticData::dollToName(i) + ", ";
        }
    }
    t+= "stored here";
    if(city->shippedThisTurn) {
        t = "Shipment from this city confirmed.";
    }
    if(!doWeHave) t = GameManager::transformationCoefficient > 15 ? "You have no demons stationed here" : "You have no dolls stored here";

    dollsHere.updateMessage(t);

    if(city->shippedThisTurn || !doWeHave) {
        for(int i = 0; i < 7; i++) {
            if(widgets[i] != &dollsHere) widgets[i]->isActive = false; else widgets[i]->isActive = true;
        }
    } else {
        for(int i = 0; i < 7; i++) {
            widgets[i]->isActive = true;
        }
    }

    t = GameManager::transformationCoefficient > 15 ? "Your forces take " + std::to_string(GameManager::shipmentTime) + " turns to arrive and harvest " + std::to_string(StaticData::dollToPrice(selectDoll.getValue())) + "souls each" : "These dolls take " + std::to_string(GameManager::shipmentTime) + " turns to arrive and cost " + std::to_string(StaticData::dollToPrice(selectDoll.getValue())) + "$ each";

    statusText.updateMessage(t);

    amountSlider.resetValues(0,city->storedDolls[selectDoll.getValue()]);

}

void ShipmentPanel::buttonCB(int) {
    if(amountSliderP->getValue() != 0) GameManager::shipDolls(currentCity,selectCityP->getValue(),selectDollP->getValue(),amountSliderP->getValue());
}

void ShipmentPanel::selectorCB(int i, int j) {
    GameManager::requestRefresh();
}

void ShipmentPanel::draw() {
    SubPanel::draw();
}

void ShipmentPanel::update(event& ev) {
    SubPanel::update(ev);
}
