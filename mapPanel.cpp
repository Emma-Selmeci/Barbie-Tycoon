#include <iostream>

#include "mapPanel.hpp"
#include "colors.hpp"
#include "graphicsHelper.hpp"


CityButton::CityButton(std::string name, Vec2 pos) : name(name), pos(pos), stringPos({pos.x+30-gout.twidth(name)/2,pos.y+32}) {

}
void CityButton::draw() {
        drawRect(pos,{30,30},{lightPink});
        cityIcon.draw({pos.x+1,pos.y+1});
        gout << color(0,0,0) << move_to(stringPos.x,stringPos.y) << text(name);
}

ImageLoader CityButton::cityIcon("textures/city2.kep");

MapPanel::MapPanel(int x, int y) : hunMap("textures/hunmap.kep"), cityButtons({
                                                                              CityButton("Gyor",{150,180}),
                                                                              CityButton("Szfvar",{220,250}),
                                                                              CityButton("Budapest",{270,220}),
                                                                              CityButton("Szhely",{80,270}),
                                                                              CityButton("Pecs",{180,380}),
                                                                              CityButton("Szeged",{400,360}),
                                                                              CityButton("Szolnok",{390,280}),
                                                                              CityButton("Miskolc",{420,140}),
                                                                              CityButton("Debrecen",{480,200}),
                                                                              CityButton("Bekes",{470,300}),
                                                                              }), x(x), y(y) {
    hunMap.setTransparent(false);
    hunMap.setPos({x,y});


}

void MapPanel::draw() {

    hunMap.draw();
    for(CityButton& c : cityButtons) c.draw();
}
