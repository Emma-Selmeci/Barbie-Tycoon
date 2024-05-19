#include "shipmentPanel.hpp"

#include "gameManager.hpp"
#include "rightPanel.hpp"

ShipmentPanel::ShipmentPanel() :
    dollsHere({pos.x+5,pos.y+5},"You have no dolls stored here"),
    whereToShip({pos.x+5,pos.y+170},"Choose which type of doll to ship and to where!"),
    selectDoll({pos.x,pos.y+230},SelectorType::DOLLSELECTOR,selectorCB,0),
    selectCity({pos.x,pos.y+270},SelectorType::CITYSELECTOR,selectorCB,0),
    amountSlider({pos.x,pos.y+320},0,0),
    statusText({pos.x+5,pos.y+350},""),
    confirmButton({pos.x+RightPanel/2,pos.y+400},,"Confirm shipment")
{
    addWidget(&dollsHere);
    addWidget(&whereToShip);
    addWidget(&selectDoll);
    addWidget(&selectCity);
    addWidget(&amountSlider);
}

void ShipmentPanel::refresh(City* city) {
    SubPanel::refresh(city);
    std::string t;
    t = "You have ";
    bool doWeHave = false;
    for(int i = 0; i < 5; i++) {
        if(city->storedDolls[i] > 0) {
                doWeHave = true;
            t+= std::to_string(city->storedDolls[i]) + " " + StaticData::dollToName(i) + ", ";
        }
    }
    t+= "stored here";
    if(!doWeHave) t = "You have no dolls stored here";
    dollsHere.updateMessage(t);




}

void ShipmentPanel::buttonCB(int) {

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
