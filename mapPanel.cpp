#include <iostream>

#include "mapPanel.hpp"
#include "colors.hpp"
#include "graphicsHelper.hpp"
#include "rightPanel.hpp"
#include "gameManager.hpp"

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
    std::string t = "TURN " + std::to_string(GameManager::turnCounter);
    gout << move_to(550,400) << text(t);
    gout << move_to(500,450) << box(150,30) << color(255,255,255) << move_to(507,457) << text("Next Turn"); //Sorry for the magic numbers :((

}

void MapPanel::update(event& ev) {
    if(!(ev.type == ev_mouse && ev.button == 1)) return;
    for(int i = 0; i < 10; i++) { //I miss .length() for primitive arrays from Java
        if(isInRect({ev.pos_x,ev.pos_y},{cityButtons[i].pos.x,cityButtons[i].pos.y},{cityButtons[i].pos.x+30,cityButtons[i].pos.y+30})) {
            RightPanel::setLoadedCity(i);
            return;
        }
    }
    if(isInRect(ev.pos_x,ev.pos_y,500,450,650,480)) {
            GameManager::nextTurn();
    }
}
