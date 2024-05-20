#include "button.hpp"

int getLength(std::string str) {
    return gout.twidth(str);
}

Button::Button(Vec2 pos, int id, buttonCallback cb, std::string message) :
    Widget(pos),
id(id),
cb(cb),
message(message),
textLength(getLength(message)) {

}



void Button::draw() {
    gout << move_to(pos.x-textLength/2-5,pos.y)
    << box(textLength+10,25) << move_to(pos.x-textLength/2,pos.y+5)
    << color(255,255,255) << text(message) << color(0,0,0);
}

void Button::drop() {}

bool Button::check(event& ev) {
    if(ev.type == ev_mouse && ev.button == 1 && isInRect(ev.pos_x,ev.pos_y,pos.x-textLength/2-5,pos.y,pos.x+textLength+10,pos.y+25)) {(*cb)(id);}
    return false;
}

bool Button::update(event& ev) {return false;}
