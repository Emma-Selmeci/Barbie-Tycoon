#ifndef HELPERS.HPP
#define HELPERS.HPP

struct Vec2 {
    int x, y;
};

bool isInRect(Vec2 p0, Vec2 p1, Vec2 p2);
bool isInRect(int, int, int, int, int, int);

#endif // HELPERS
