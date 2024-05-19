#include "selector.hpp"

#include <iostream>

#include "mainScreen.hpp"
#include "staticData.hpp"

std::string Selector::barbieTypes[] = {
    "Simple Doll",
    "Dressable Doll",
    "Perfect Doll",
    "His Doll",
    "Nephilim",
};

Selector::Selector(Vec2 pos, SelectorType type, selectorCallback f, int id) : Widget(pos), f(f), type(type), id(id) {

}

void Selector::draw() {
    std::string valText = type == SelectorType::DOLLSELECTOR ? barbieTypes[value] : barbieTypes[value]; //This should be changed when cities will be included
    int sLength = gout.twidth(valText);
    gout << move_to(pos.x+MainScreen::rightWidth/2-sLength/2,pos.y+gout.cascent()) << text(valText);
    StaticData::leftArrow.draw({pos.x+5,pos.y});
    StaticData::rightArrow.draw({pos.x+MainScreen::rightWidth-35,pos.y});
}

bool Selector::check(event& ev) {
    if(!(ev.type == ev_mouse && ev.button == 1)) return false;
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+5,pos.y,pos.x+35,pos.y+30)) {
        value--;
    } else
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+MainScreen::rightWidth-35,pos.y,pos.x+MainScreen::rightWidth-5,pos.y+30)) {
        value++;
    }
    boundValue();
    return false;
}

void Selector::boundValue() {
    f(value,id);
}

void Selector::forceSelection(int newValue) {
    value = newValue;
    boundValue();
}

int Selector::getValue() {return value;}

void Selector::drop() {}
bool Selector::update(event& ev) {return false;}
