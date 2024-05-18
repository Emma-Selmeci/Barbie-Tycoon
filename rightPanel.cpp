#include "rightPanel.hpp"

#include <iostream>

#include "graphics.hpp"
#include "graphicsHelper.hpp"
#include "colors.hpp";

using namespace genv;


#define ws << " " <<

//I'm glad I've studied the order of initialization when I was studying Java or I'd be in big big trouble right now

/*
Procudtion, Parts, Workers, R&D,
*/

static int iconyOffset = 35, iconSize = 30;

Mode RightPanel::selectedMenu = Mode::PRODUCTION;
Vec2 RightPanel::size;
Vec2 RightPanel::pos;
City* RightPanel::loadedCity = &City::cities[2];
int RightPanel::menuPlaces[];

ImageLoader RightPanel::menuImages[] = {
    ImageLoader("textures/productionMenu.kep"),
    ImageLoader("textures/shippingMenu.kep"),
    ImageLoader("textures/partsMenu.kep"),
    ImageLoader("textures/workerMenu.kep"),
    ImageLoader("textures/researchMenu.kep"),
};

void RightPanel::setDim(Vec2 initialPos, Vec2 initialSize) {
    size = initialSize; pos = initialPos;
    int delta = (size.x - 5*30) / 6;
    for(int i = 0; i<5 ; i++) {
        menuPlaces[i]=pos.x+delta*(i+1)+i*30;
        menuImages[i].setPos({pos.x+delta*(i+1)+i*30+1,pos.y+1+iconyOffset});
        menuImages[i].setTransparent(false);
    }
}

void RightPanel::draw() {
    drawRect({pos.x,pos.y},{size.x,size.y},{lightPink});
    int cityNameSize = gout.twidth(loadedCity->name);
    gout << color(0,0,0) << move_to(pos.x+size.x/2-cityNameSize/2,pos.y+10) << text(loadedCity->name);
    for(int i = 0; i < 5; i++) {
            i == selectedMenu ? gout << color(0,0,0) : gout << color(255,255,255);
            drawRect({menuPlaces[i],pos.y+iconyOffset},{iconSize,iconSize});
            menuImages[i].draw();
    }
}

void RightPanel::update(event& ev) {
    //Select Menus
    if(ev.type == ev_mouse && ev.button == 1) {
        for(int i = 0; i < 5; i++) {
            if(isInRect({ev.pos_x,ev.pos_y},{menuPlaces[i],iconyOffset+pos.y},{menuPlaces[i]+iconSize,iconyOffset+iconSize+pos.y})) {
                selectedMenu = intToMode(i);
                return;
            }
        }
    }
}

Mode RightPanel::intToMode(int i) {
    switch(i) {
        case 0 : return Mode::PRODUCTION;
        case 1 : return Mode::SHIPPING;
        case 2 : return Mode::PARTS;
        case 3 : return Mode::WORKERS;
        case 4 : return Mode::RESEARCH;
    }
}

void RightPanel::setLoadedCity(int cityId) {
    loadedCity = &City::cities[cityId];
    draw();
    gout << refresh;
}
