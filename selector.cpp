#include "selector.hpp"

#include "mainScreen.hpp"
#include "staticData.hpp"
#include "city.hpp"
#include "research.hpp"

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
    std::string valText = type == SelectorType::DOLLSELECTOR ? barbieTypes[value] : City::cityToName(value); //This should be changed when cities will be included
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
    if(type == SelectorType::CITYSELECTOR) {
        if(value > 9) value = 9; else if(value < 0) value = 0;
    } else {
        if(value < 0) value = 0;
        int max = 0;
        if(Research::wasResearched(ResearchEnum::DOLL2)) max = 1;
        if(Research::wasResearched(ResearchEnum::DOLL3)) max = 2;
        if(Research::wasResearched(ResearchEnum::DOLL4)) max = 3;
        if(Research::wasResearched(ResearchEnum::DOLL5)) max = 4;
        if(value > max) value = max;

    }
    f(value,id);
}

void Selector::forceSelection(int newValue) {
    value = newValue;
    boundValue();
}

int Selector::getValue() {return value;}

void Selector::drop() {}
bool Selector::update(event& ev) {return false;}
