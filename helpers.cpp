#include <iostream> //For debugging
#define ws << " " <<

#include "helpers.hpp"

bool isInRect(Vec2 p0, Vec2 p1, Vec2 p2) {
    return p0.x > p1.x && p0.x < p2.x && p0.y > p1.y && p0.y < p2.y;
}
