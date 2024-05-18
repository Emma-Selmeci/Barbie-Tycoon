#include "graphics.hpp"

#include "graphicsHelper.hpp"

using namespace genv;

void drawRect(Vec2 p1, Vec2 p2) {
    gout << move_to(p1.x,p1.y) << box(p2.x,p2.y);
}

void drawRect(int p1x, int p1y, int p2x, int p2y) { //Halfway through the project I've realized that my code was running slow so I'd implemented these
    gout << move_to(p1x,p1y) << box(p2x,p2y);
}

void drawRect(Vec2 p1, Vec2 p2, Color c) {
    gout << color(c.r,c.g,c.b);
    drawRect(p1,p2);
}

void drawRect(int p1x, int p1y, int p2x, int p2y, int r, int g, int b) {
    gout << color(r,g,b);
    drawRect(p1x,p1y,p2x,p2y);
}

void drawSpecialRect(int p1x, int p1y, int p2x, int p2y, int r1, int g1, int b1, int r2, int g2, int b2) {
    gout << color(r1,g1,b1) << move_to(p1x,p1y) << box(p2x,p2y) << color(r2,g2,b2) << move_to(p1x+1,p1y+1) << box(p2x-2,p2y-2);
}
