#include "messagePanel.hpp"

#include <iostream>

#include "graphics.hpp"

#include "graphicsHelper.hpp"
#include "colors.hpp"

using namespace genv;

ImageLoader MessagePanel::advisorImage("textures/assistant.kep");
Vec2 MessagePanel::pos;
Vec2 MessagePanel::size;
Vec2 MessagePanel::replyP1;
Vec2 MessagePanel::replyP2;

void drawString(std::string str) {
    gout << color(0,0,0);
    int lock = 0, y = 100;

    for(int i = 1; i < str.length()+1; i++) {

        if(i == str.length()) {
            gout << move_to(200,y) << text(str.substr(lock,i-lock));
            break;
        }

        if(gout.twidth(str.substr(lock,i-lock)) > 450) {

            for(int j = i; j > 0; j--) {

                if(str[j] == ' ') {

                    gout << move_to(200,y) << text(str.substr(lock,j-lock));
                    lock = j+1;
                    i = j+1;
                    y+=20;
                    break;
                }
            }
        }
    }
}

void MessagePanel::draw() {
    drawRect(pos,size,{lightPink});
    advisorImage.draw({pos.x+50,pos.y+100});
    drawString("Good Morning sir! It's a pleasure to meet you! I'm glad things are back in track with you being the CEO of the Barbie company. I'm your chief advisor and you can expect me to tell you all sorts of important information in the future.");
    std::string response = "Got it!";
    int messageLength = gout.twidth(response);
    replyP1 = {pos.x+size.x/2-messageLength/2-5,pos.y+size.y-30};
    replyP2 = {replyP1.x+messageLength+10,replyP1.y+25};
    drawRect(replyP1,{replyP2.x-replyP1.x,replyP2.y-replyP1.y});
    gout << color(255,255,255) << move_to(replyP1.x+5,replyP1.y+5) << text(response);
}

void MessagePanel::loadMessages(event& ev) {
    while(gin >> ev) {
        if(ev.type == ev_mouse && ev.button == 1 && isInRect({ev.pos_x,ev.pos_y}, replyP1 , replyP2 )) {
            return;
        }
    }
}

void MessagePanel::setPos(Vec2 initialPos, Vec2 initialSize) {
    MessagePanel::pos = initialPos;
    MessagePanel::size = initialSize;
}
