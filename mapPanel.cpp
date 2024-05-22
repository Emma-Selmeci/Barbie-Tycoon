#include <iostream>

#include "mapPanel.hpp"
#include "colors.hpp"
#include "graphicsHelper.hpp"
#include "rightPanel.hpp"
#include "gameManager.hpp"
#include "research.hpp"

CityButton::CityButton(std::string name, Vec2 pos, int id) : name(name), pos(pos), stringPos({pos.x+30-gout.twidth(name)/2,pos.y+32}), id(id) {

}
void CityButton::draw() {
        if(Research::wasResearched(ResearchEnum::SECRET) && id == 9) return;
        drawRect(pos,{30,30},{lightPink});
        GameManager::transformationCoefficient > 15 ? cityIconBad.draw({pos.x+1,pos.y+1}) : cityIcon.draw({pos.x+1,pos.y+1});
        gout << color(0,0,0) << move_to(stringPos.x,stringPos.y) << text(City::cityToName(id));
}

ImageLoader CityButton::cityIcon("textures/city2.kep");
ImageLoader CityButton::cityIconBad("textures/corruptedcity.kep");

MapPanel::MapPanel(int x, int y) : hunMap("textures/hunmap.kep"),
hunMap1("textures/hunmap1.kep"),
hunMap2("textures/hunmap2.kep"),
hunMap3("textures/hunmap3.kep"),
hunMap4("textures/hunmap4.kep"),
hunMap5("textures/hunmap5.kep"),
hunMap6("textures/hunmap6.kep"),
cityButtons({
                                                                              CityButton("Gyor",{150,180},0),
                                                                              CityButton("Szfvar",{220,250},1),
                                                                              CityButton("Budapest",{270,220},2),
                                                                              CityButton("Szhely",{80,270},3),
                                                                              CityButton("Pecs",{180,380},4),
                                                                              CityButton("Szeged",{400,360},5),
                                                                              CityButton("Szolnok",{390,280},6),
                                                                              CityButton("Miskolc",{420,140},7),
                                                                              CityButton("Debrecen",{480,200},8),
                                                                              CityButton("Bekes",{470,300},9),
                                                                              }), x(x), y(y) {
    hunMap.setTransparent(false);
    hunMap.setPos({x,y});
    hunMap1.setTransparent(false);
    hunMap1.setPos({x,y});
    hunMap2.setTransparent(false);
    hunMap2.setPos({x,y});
    hunMap3.setTransparent(false);
    hunMap3.setPos({x,y});
    hunMap4.setTransparent(false);
    hunMap4.setPos({x,y});
    hunMap5.setTransparent(false);
    hunMap5.setPos({x,y});
    hunMap6.setTransparent(false);
    hunMap6.setPos({x,y});
}

void MapPanel::draw() {
    if(GameManager::transformationCoefficient > 50) {
        hunMap3.draw();
    } else if(GameManager::transformationCoefficient > 35) {
        hunMap2.draw();
    }
    else if(GameManager::transformationCoefficient > 5) {
        hunMap1.draw();
    } else {
        hunMap.draw();
    }

    for(CityButton& c : cityButtons) c.draw();
    std::string t = "TURN " + std::to_string(GameManager::turnCounter);
    gout << move_to(550,400) << text(t);
    gout << move_to(500,450) << box(150,30) << color(255,255,255) << move_to(507,457) << text("Next Turn"); //Sorry for the magic numbers :((

}

void MapPanel::update(event& ev) {
    if(!(ev.type == ev_mouse && ev.button == 1)) return;
    for(int i = 0; i < 10; i++) { //I miss .length() for primitive arrays from Java
        if(Research::wasResearched(ResearchEnum::SECRET) && i == 9) continue;
        if(isInRect({ev.pos_x,ev.pos_y},{cityButtons[i].pos.x,cityButtons[i].pos.y},{cityButtons[i].pos.x+30,cityButtons[i].pos.y+30})) {
            RightPanel::setLoadedCity(i);
            return;
        }
    }
    if(isInRect(ev.pos_x,ev.pos_y,500,450,650,480)) {
            GameManager::nextTurn();
    }
}
