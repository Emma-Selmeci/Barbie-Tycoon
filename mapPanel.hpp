#ifndef MAPPANEL.HPP
#define MAPPANEL.HPP

#include "imageLoader.hpp"

class MapPanel;

class CityButton {
    std::string name;
    static ImageLoader cityIcon;
    static ImageLoader cityIconBad;
    Vec2 pos;
    Vec2 stringPos;
    int id;
public:
    CityButton(std::string name, Vec2 pos, int id);
    void draw();
    friend class MapPanel;
};

class MapPanel {
    ImageLoader hunMap;
    ImageLoader hunMap1, hunMap2, hunMap3, hunMap4, hunMap5, hunMap6;
    CityButton cityButtons[10];
    const int x, y;
public:
    MapPanel(int x, int y);
    void draw();
    void update(event&);
};

#endif // MAPPANEL
