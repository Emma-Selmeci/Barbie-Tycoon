#include "helpers.hpp"

bool isInRect(Vec2 p0, Vec2 p1, Vec2 p2) {
    return p0.x > p1.x && p0.x < p2.x && p0.y > p1.y && p0.y < p2.y;
}

bool isInRect(int p0x, int p0y, int p1x, int p1y, int p2x, int p2y) {
    return p0x > p1x && p0x < p2x && p0y > p1y && p0y < p2y;
}
