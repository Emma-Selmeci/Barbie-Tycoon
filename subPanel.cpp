#include "subPanel.hpp"

//I'm sorry, I'm gonna just write the magic number in here :/
Vec2 SubPanel::pos;
City* SubPanel::currentCity = &City::cities[2];

void SubPanel::setPos(Vec2 newPos) {
    pos = newPos;
}

void SubPanel::updatePos() {
    for(int i = 0; i < widgets.size(); i++) {
            widgets[i]->rePos({pos.x,pos.y});
            }
}

void SubPanel::update(event& ev) {
    bool didWeTakeAnAction = false;
    if(focusedWidget != 0) {
            didWeTakeAnAction = focusedWidget->update(ev);
    }

    if(!didWeTakeAnAction) {
        checkAllWidgets(ev);
    }

}

void SubPanel::draw() {
    drawWidgets();
}

void SubPanel::addWidget(Widget* w) {
    widgets.push_back(w);
}

void SubPanel::checkAllWidgets(event& ev) {
    for(int i = widgets.size()-1; i >= 0; i--) {
        if(widgets[i]->isActive && widgets[i]->check(ev)) {
            if(focusedWidget != 0 && focusedWidget != widgets[i]) focusedWidget->drop();
            focusedWidget = widgets[i];
            return;
        }
    }
}

void SubPanel::drawWidgets() {
    for(int i = 0; i < widgets.size(); i++) {
        if(widgets[i] -> isActive) widgets[i]->draw();
    }
}

void SubPanel::refresh(City* newCity) {
    currentCity = newCity;
}
