#include "messagePanel.hpp"

#include "graphics.hpp"

#include "graphicsHelper.hpp"
#include "colors.hpp"
#include "gameManager.hpp"
#include "research.hpp"

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
                loadedEvents[i]->doEffect();
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


    events.push_back({"Good Morning, Sir! We've got lot of things to do so I'm glad to finally see you here in your office.","Who are you?",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 1) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Good question, Sir, I'm the branch assistant manager of this company, but let's just stick to advisor for now. I'll be giving you all the information you need to become a star CEO!","Let's hear it!",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 1) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"That's the spirit, Sir! Well, as you know, Barbie dolls are not made out of thin air. We need some parts for them. Parts can be purchased in cities with factories. If I'm not mistaken, you have such a factory in Budapest.","That's right",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 1) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Why don't you order some parts? Just don't blow all the company cash yet, we need to pay our workers each turn. The parts should arrive in a turn, and I'll be back with more instructions. Feel free to look around but your options are quite restricted now.","Let's get down to business..",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 1) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Hopefully you've bought a bunch of parts for our dolls by now. Why don't you order those lazy sloths in the factory to do some work and produce some shiny new Barbie dolls? As you can see, only one type of doll is available to us now, but that'll change in the very near future!","Let's make some dolls",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 2) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"If everything is right, you've produced some dolls. You can see this in the shipment menu, where you can select where you want these dolls to be sold. You should check the fourth panel on each city to see if there is any demand for your dolls.","Sounds complicated...",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 3) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Oh, it get's worse. You need to make sure you only transport the dolls to cities with demand or you won't make a profit. Keep in mind that dolls take 3 days to arrive with our current trucks - they are quite old trucks you see...","That's unfair!",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 3) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Don't worry, there is something to help you. Some cities will grow a fanbase as you sell more and more dolls. These cities will be a reliable source of income for you. A few turns and you'll notice!","Thank you for your help, mr. Advisor",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 3) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"While we're waiting for the products to arrive, we should take a look at our R&D. I've heard that your first lab was just finished in Budapest and it will generate research points for you. There is a tech-tree on the bottom where you can unlock brand new dolls, improvements and more!","Can't wait!",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 4) return true; else return false;
                     },0,[](){
                        GameManager::buildLab(&City::cities[2]);
                     }});

    events.push_back({"There is one last thing you need to know, Sir. The workers, well, they tend to go on strike every once in a while. You can choose to ignore them, and they'll be back making dolls in a few turns. If you can't afford the loss, you can agree to increase their payments. If I'm not mistaken, workers are on strike at the moment in Budapest, you should check the situation in the 4th menu. There is a chance they will have already stopped striking when you get there.","Those workers...",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 5) return true; else return false;
                     },0,[](){
                        GameManager::forceStrike(&City::cities[2]);
                     }});

    events.push_back({"Sir, I've seen the design on the new doll and I won't deny that I'm amazed. The ribbon is an especially nice touch. We will make more profit on this new doll than the regular one. But don't worry, there is still demand for the old dolls as well.","There's no stopping",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::DOLL2)) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Good news, we can build shops now. They're not that special but if we build a shop in a city where demand for our dolls is high, we can increase our profits. I hope you're aware of the cities that have the most following by now, Sir","Of course, shop-building time",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::SHOP)) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"All right, Sir, that's all you have to know for now. I'll be back once you make some progress","See you soon!",false,&advisorImage,[](){
                     if(GameManager::turnCounter == 6) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Sir, I've got some great news! People love your Barbie dolls! They can't get enough! I hope you were serious about this \"getting rich\" thing, because we're hitting bit. Your late father would have been very proud of you!","Wonderful news",false,&advisorImage,[](){
                     if(!Research::isLocked(2)) return true; else return false;
                     },2,[](){

                     }});

    events.push_back({"Sir, remember those old trucks I've mentioned? We got some new ones. You know what that means? Shipping dolls only takes 2 turns now. There is still room to improve though...","Prepare the racing cars",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::TRANS2)) return true; else return false;
                     },0,[](){
                        GameManager::decreaseShipmentTime();
                     }});

    events.push_back({"Sir, come to the window quickly. There are people protesting down there. \"Give us more dolls\" they shout","Everybody loves our dolls",false,&advisorImage,[](){
                     if(!Research::isLocked(4)) return true; else return false;
                     },2,[](){

                     }});

    events.push_back({"It was about time we improved out business strategies! We can now use marketing to increase demand for our products. It costs some money but it's quite useful if you've got too many dolls collecting dust in your stores.","Good idea",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::MARKETING)) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"A short documentary was aired about our most obsessed fan on TV - she's an 11 years old girl who owns more than a 100 Barbie dolls. This will surely boost our sales.","That's adorable",false,&advisorImage,[](){
                     if(!Research::isLocked(4)) return true; else return false;
                     },4,[](){

                     }});

    events.push_back({"Sir... I've got some bad news. The girl from the documentary.. Well, she died somehow. She was found in her room, surrounded by her dolls. It's a tragedy!","That's terrible",false,&advisorImage,[](){
                     if(!Research::isLocked(4)) return true; else return false;
                     },6,[](){

                     }});

    events.push_back({"We did it, Sir! Due to the success of our company, we were given permission to open factories all around the country! Isn't this wonderful?","A happy day indeed",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::MOREFACTORIES)) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"I know you've not been the happiest with the speed at which research is going, and luckily, our boys have fixed the problem. We can now build labs in any city for a price.","I like labs!",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::MORERESEARCH)) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Sir, I'm excited about the future of this company. I've taken out a loan and bought a new house for my family. I hope you do the same with yours","Things still could be better",false,&advisorImage,[](){
                     if(!Research::isLocked(6)) return true; else return false;
                     },3,[](){

                     }});

}
    MessagePanel::pos = initialPos;
    MessagePanel::size = initialSize;
}
