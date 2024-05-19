#include "partsPanel.hpp"

#include <iostream>

#include "graphics.hpp"

#include "testWidget.hpp"
#include "gameManager.hpp"
#include "button.hpp"
#include "mainScreen.hpp"

using namespace genv;

static const int textLength = gout.twidth("Confirm")*2;
Slider* PartsPanel::sliderp;

PartsPanel::PartsPanel() :
    partSlider({0,90},0,GameManager::money/10),
    storedParts({pos.x+5,pos.y+5},std::to_string(currentCity->storedParts) + " parts stored"),
    arrivingParts({pos.x+5, pos.y+210},std::to_string(currentCity->shippingParts) + " parts arrive next turn") {
    sliderp = &partSlider;
    addWidget(&partSlider);
    addWidget(&storedParts);
    addWidget(&arrivingParts);
    addWidget(new TextWidget({pos.x+5,pos.y+45},"Puchase parts! 10$ each"));
    addWidget(new Button({pos.x+MainScreen::rightWidth/2,pos.y+160},0,buttonPressed,"Confirm"));
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
    partSlider.resetValues(0,GameManager::money/10);
    std::string t = std::to_string(currentCity->storedParts) + " parts stored";
    storedParts.updateMessage(t);
    t = std::to_string(currentCity->shippingParts) + " parts arrive next turn";
    arrivingParts.updateMessage(t);
}
