#ifndef GRAPHICSHELPER.HPP
#define GRAPHICSHELPER.HPP

#include "helpers.hpp"

struct Color {
    short int r, g, b;
};

void drawRect(Vec2 p1, Vec2 p2);

void drawRect(Vec2 p1, Vec2 p2, Color c);

#endif // GRAPHICSHELPER
