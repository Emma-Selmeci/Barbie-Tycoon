#include "rightPanel.hpp"

#include "graphics.hpp"

using namespace genv;

//I'm glad I've studied the order of initialization when I was studying Java or I'd be in big big trouble right now

/*
Procudtion,
*/

enum Mode {
    PRODUCTION,
    WORKERS,
    RESEARCH,

};

Vec2 RightPanel::size;
Vec2 RightPanel::pos;
City* RightPanel::loadedCity = &City::cities[2];

void RightPanel::setDim(Vec2 initialPos, Vec2 initialSize) {
    size = initialSize; pos = initialPos;
}

void RightPanel::draw() {
    int cityNameSize = gout.twidth(loadedCity->name);
    gout << color(0,0,0) << move_to(pos.x+size.x/2-cityNameSize/2,pos.y+10) << text(loadedCity->name);
}
