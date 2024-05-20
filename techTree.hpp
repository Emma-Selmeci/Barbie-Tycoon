#ifndef TECHTREE.HPP
#define TECHTREE.HPP

#include "graphics.hpp"

#include "helpers.hpp"
#include "research.hpp"

using namespace genv;

class TechTree {
    static Vec2 pos, size;
    static int currentPos;
    static void drawTech(Research*, bool);
    static Vec2 sub;
    static void boundValue();
public:
    static void update(event&);
    static void setDim(Vec2, Vec2);
    static void draw();
};

#endif // TECHTREE
