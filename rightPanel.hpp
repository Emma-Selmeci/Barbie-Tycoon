#ifndef RIGHTPANEL.HPP
#define RIGHTPANEL.HPP

#include "city.hpp"
#include "helpers.hpp"
#include "imageLoader.hpp"

enum Mode {
    PRODUCTION,
    SHIPPING,
    PARTS,
    WORKERS,
    RESEARCH,
};

class RightPanel {
    static City* loadedCity;
    static Vec2 pos; //This Vec2 kicked a puppy in the face. They're a total POS
    static Vec2 size;
    static ImageLoader menuImages[5];
    static int menuPlaces[5];
    static Mode selectedMenu;
    static void selectMenu();
    static Mode intToMode(int);
public:
    static void setDim(Vec2, Vec2);
    static void draw();
    static void update(event&);
    static void setLoadedCity(int);
};

#endif // RIGHTPANEL
