#ifndef MAPPANEL.HPP
#define MAPPANEL.HPP

#include "imageLoader.hpp"

class MapPanel;

class CityButton {
    std::string name;
    static ImageLoader cityIcon;
    Vec2 pos;
    Vec2 stringPos;
public:
    CityButton(std::string name, Vec2 pos);
    void draw();
    friend class MapPanel;
};

class MapPanel {
    ImageLoader hunMap;
    CityButton cityButtons[10];
    const int x, y;
public:
    MapPanel(int x, int y);
    void draw();
    void update(event&);
};

#endif // MAPPANEL
