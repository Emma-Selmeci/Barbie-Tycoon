#include <iostream>

#include "mainMenu.hpp"
#include "helpers.hpp"
#include "mainScreen.hpp"

const static int highlightx1 = 100, highlightx2 = 300, highlighty = 245, highlightDelta = 30, headx = 55;

MainMenu::MainMenu(event& ev) : background("textures/mainMenuBackground.kep"), barbieHead("textures/barbieHead.kep") {
    background.draw();
    gout << color(0,0,0);
    gout.load_font("classic.ttf",15);
    barbieHead.setTransparent(false);
    gout << move_to(60,115) << text("A GAME ABOUT THE MAGICAL") << move_to(60,135) << text("POWER OF FRIENDSHIP");
    gout.load_font("classic.ttf",20);
    gout << color(0,0,0) << move_to(100,250) << text("Start Game") << move_to(100,280) << text("Exit");
    gout << refresh;

    eventLoop(ev);
}

void MainMenu::eventLoop(event& ev) {
    while(gin >> ev) {
        if(ev.type == ev_mouse) {
            if(ev.button == 0) {
                short int newState;
                newState = -1;
                if(isInRect({ev.pos_x,ev.pos_y},{highlightx1,highlighty},{highlightx2,highlighty+highlightDelta})) newState = 0;
                if(isInRect({ev.pos_x,ev.pos_y},{highlightx1,highlighty+highlightDelta},{highlightx2,highlighty+highlightDelta*2})) newState = 1;
                if(newState != state) {
                    state = newState;
                    reDraw();
                }
            } else if(ev.button == 1) {
                if(state == 1) exit(1);
                if(state == 0) {
                    break;
                }
            }
        }
    }
    MainScreen m(ev);
}

void MainMenu::reDraw() { //Abusing the fact that I don't have to redraw this every frame
    gout << color(255,182,193) << move_to(headx,highlighty) << box_to(highlightx1,highlighty+highlightDelta*2);
    if(state != -1) {
            barbieHead.draw({headx,highlighty+state*highlightDelta});
            }
    gout << refresh;
}
