#ifndef GRAPHICSHELPER.HPP
#define GRAPHICSHELPER.HPP

#include "helpers.hpp"

struct Color {
    short int r, g, b;
};

void drawRect(Vec2 p1, Vec2 p2);

void drawRect(int p1x, int p1y, int p2x, int p2y);

void drawRect(Vec2 p1, Vec2 p2, Color c);

void drawRect(int p1x, int p1y, int p2x, int p2y, int r, int g, int b);

void drawSpecialRect(int p1x, int p1y, int p2x, int p2y, int r1, int g1, int b1, int r2, int g2, int b2);

#endif // GRAPHICSHELPER
