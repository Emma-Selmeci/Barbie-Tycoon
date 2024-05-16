#ifndef RIGHTPANEL.HPP
#define RIGHTPANEL.HPP

#include "city.hpp"
#include "helpers.hpp"

class RightPanel {
    static City* loadedCity;
    static Vec2 pos; //This Vec2 kicked a puppy in the face. They're a total POS
    static Vec2 size;
public:
    static void setDim(Vec2, Vec2);
    static void draw();
};

#endif // RIGHTPANEL
