#include "slider.hpp"

#include <cmath>

#include "graphics.hpp"

#include "mainScreen.hpp"
#include "staticData.hpp"
#include "graphicsHelper.hpp"
#include "colors.hpp"
#include "helpers.hpp"

using namespace genv;

static int width = MainScreen::rightWidth;

Slider::Slider(Vec2 pos, int min, int max) : Widget(pos),  min(min), max(max), value(min) {
}

void Slider::resetValues(int newMin, int newMax) {
    min = newMin; max = newMax;
    boundValue();
    //Recalibrate currentValue
    //Reset graphics
}

void Slider::draw() {
    std::string valText = std::to_string(value);
    int sLength = gout.twidth(valText);
    gout << move_to(pos.x+width/2-sLength/2,pos.y+gout.cascent()) << text(valText);
    StaticData::leftArrow.draw({pos.x+5,pos.y});
    StaticData::rightArrow.draw({pos.x+width-35,pos.y});
    drawSpecialRect(pos.x+5,pos.y+35,width-10,10,GUIvioletDark,0,0,0);

    int sliderPos;
    if(min == max) {
        sliderPos = pos.x+5;
    } else {
        int delta = max-min;
        float absVal = value-min;
        float variant = absVal/delta;
        sliderPos = pos.x+5+(width-10)*variant;
    }
    drawSpecialRect(sliderPos-5,pos.y+30,10,20,GUIvioletDark,0,0,0);
}

void Slider::drop() {
}

bool Slider::check(event& ev) {
    if(ev.type == ev_mouse && ev.button == 1) {
        return mouseClicked(ev);
    }
    return false;
}

bool Slider::mouseClicked(event& ev) {
    if(min == max) return false;
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+5,pos.y,pos.x+35,pos.y+30)) {
        value--;
        boundValue();
        return false;
    }
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+width-35,pos.y,pos.x+width-5,pos.y+30)) {
        value++;
        boundValue();
        return false;
    }
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+5,pos.y+30,pos.x+width-5,pos.y+50)) {
        pressed = true;
        return true;
    }
}

void Slider::boundValue() {
    value = value < min ? min : value > max ? max : value;
}

bool Slider::update(event& ev) {
    if(ev.type == ev_mouse && pressed) {
        int posRel = ev.pos_x-(pos.x+5);
        int delta = max-min;
        float fraction = posRel/ ((float)width-10);
        float aprox = min + fraction*delta;
        value = round(aprox);
        boundValue();
        if(ev.button == 0) {return true;} else {pressed = false; return false;}
    }
    return false;
}

int Slider::getValue() {return value;}
void Slider::forceValue(int newValue) {
    value = newValue;
}
