#include "partsPanel.hpp"

#include <iostream>

#include "graphics.hpp"

#include "testWidget.hpp"
#include "gameManager.hpp"

#include "mainScreen.hpp"

using namespace genv;

static const int textLength = gout.twidth("Confirm")*2;
Slider* PartsPanel::sliderp;

PartsPanel::PartsPanel() :
    partSlider({0,90},0,GameManager::money/10),
    storedParts({pos.x+5,pos.y+5},std::to_string(currentCity->storedParts) + " parts stored"),
    arrivingParts({pos.x+5, pos.y+210},std::to_string(currentCity->shippingParts) + " parts arrive next turn"),
    purchasePlease({pos.x+5,pos.y+45},"Puchase parts! 10$ each"),
    confirmButton({pos.x+MainScreen::rightWidth/2,pos.y+160},0,buttonPressed,"Confirm"),
    noFactoryButton({pos.x+5,pos.y+5},"You have no factory in this city! Build a factory to order parts") {
    sliderp = &partSlider;
    addWidget(&partSlider);
    addWidget(&storedParts);
    addWidget(&arrivingParts);
    addWidget(&purchasePlease);
    addWidget(&confirmButton);
    noFactoryButton.isActive = false;
    addWidget(&noFactoryButton);
}

void PartsPanel::draw() {
    SubPanel::draw();
}

void PartsPanel::update(event& ev) {
    SubPanel::update(ev);
}

void PartsPanel::buttonPressed(int id) {
    GameManager::purchaseParts(currentCity,sliderp->getValue());
}

void PartsPanel::refresh(City* city) {
    SubPanel::refresh(city);
    if(city->hasFactory) {
        partSlider.isActive = true;
        storedParts.isActive = true;
        arrivingParts.isActive = true;
        purchasePlease.isActive = true;
        confirmButton.isActive = true;
        noFactoryButton.isActive = false;
    } else {
        partSlider.isActive = false;
        storedParts.isActive = false;
        arrivingParts.isActive = false;
        purchasePlease.isActive = false;
        confirmButton.isActive = false;
        noFactoryButton.isActive = true;
    }
    partSlider.resetValues(0,GameManager::money/10);
    partSlider.forceValue(0);
    std::string t = std::to_string(currentCity->storedParts) + " parts stored";
    storedParts.updateMessage(t);
    t = std::to_string(currentCity->shippingParts) + " parts arrive next turn";
    arrivingParts.updateMessage(t);
}
