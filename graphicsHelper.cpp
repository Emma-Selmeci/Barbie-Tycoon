#include "graphics.hpp"

#include "graphicsHelper.hpp"

using namespace genv;

void drawRect(Vec2 p1, Vec2 p2) {
    gout << move_to(p1.x,p1.y) << box(p2.x,p2.y);
}

void drawRect(Vec2 p1, Vec2 p2, Color c) {
    gout << color(c.r,c.g,c.b);
    drawRect(p1,p2);
}
