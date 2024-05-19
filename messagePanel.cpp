#include "messagePanel.hpp"

#include <iostream>

#include "graphics.hpp"

#include "graphicsHelper.hpp"
#include "colors.hpp"
#include "gameManager.hpp"

using namespace genv;

ImageLoader MessagePanel::advisorImage("textures/assistant.kep");
Vec2 MessagePanel::pos;
Vec2 MessagePanel::size;
Vec2 MessagePanel::replyP1;
Vec2 MessagePanel::replyP2;
std::vector<GameEvent> MessagePanel::events;
std::vector<GameEvent*> MessagePanel::loadedEvents;

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

void MessagePanel::draw(GameEvent* gameEvent) {
    drawRect(pos,size,{lightPink});
    gameEvent->image->draw({pos.x+50,pos.y+100});
    gout << color(0,0,0);
    for(int i = 0; i < gameEvent->message.size(); i++) {
        gout << move_to(200,100+i*20) << text(gameEvent->message[i]);
    }
    if(gameEvent->isHebrew) {gout.load_font("hebrew.ttf",15);}
    int messageLength = gout.twidth(gameEvent->response);
    replyP1 = {pos.x+size.x/2-messageLength/2-5,pos.y+size.y-30};
    replyP2 = {replyP1.x+messageLength+10,replyP1.y+25};
    drawRect(replyP1,{replyP2.x-replyP1.x,replyP2.y-replyP1.y});
    gout << color(255,255,255) << move_to(replyP1.x+5,replyP1.y+5) << text(gameEvent->response) << refresh;
    if(gameEvent->isHebrew) {gout.load_font("classic.ttf",15);}
}

void MessagePanel::loadMessages(event& ev) {
    getMessages();
    for(int i = 0; i < loadedEvents.size(); i++) {
        draw(loadedEvents[i]);
        while(gin >> ev) {
            if(ev.type == ev_mouse && ev.button == 1 && isInRect({ev.pos_x,ev.pos_y}, replyP1 , replyP2 )) {
                break;
            }
        }
    }
}

void MessagePanel::getMessages() {
    loadedEvents.clear();
    for(int i = 0; i < events.size(); i++) {
        if(events[i].check()) loadedEvents.push_back(&events[i]);
    }
}

void MessagePanel::setPos(Vec2 initialPos, Vec2 initialSize) {
    //Doing initialization here so that they are done during the loading scene
{


    events.push_back({"This is a test event :)","I see",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 1) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"This is a second message to see if everything's working. Also, this one is longer xd","שלום",true,&advisorImage,[](){
                     if(GameManager::turnCounter == 1) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"It's the second turn","Wow, already?",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 2) return true; else return false;
                     },0,[](){

                     }});

}
    MessagePanel::pos = initialPos;
    MessagePanel::size = initialSize;
}
