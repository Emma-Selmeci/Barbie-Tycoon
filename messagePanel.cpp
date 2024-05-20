#include "messagePanel.hpp"

#include "graphics.hpp"

#include "graphicsHelper.hpp"
#include "colors.hpp"
#include "gameManager.hpp"
#include "research.hpp"
#include "mainScreen.hpp"
#include "endCredits.hpp"

using namespace genv;

ImageLoader MessagePanel::advisorImage("textures/assistant.kep");
ImageLoader MessagePanel::visitorImage("textures/visitor.kep");
ImageLoader MessagePanel::blank("textures/blank.kep");
ImageLoader MessagePanel::transformingAdvisorImage("textures/transformingassistant.kep");
ImageLoader MessagePanel::transformedAdvisorImage("textures/corruptedassistant.kep");
ImageLoader MessagePanel::darkAdvisorImage("textures/darkassistant.kep");
ImageLoader MessagePanel::demonAdvisorImage("textures/demonadvisor.kep");
bool MessagePanel::specialFlag = false;
bool MessagePanel::cutSceneFlag = false;
bool MessagePanel::endFlag = false;
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
    Color c{lightPink};
    c = transformColor(c,false);
    if(!specialFlag) drawRect(pos,size,{c}); else drawRect(0,0,999,599,0,0,0);
    gameEvent->image->draw({pos.x+50,pos.y+100});
    if(!specialFlag) gout << color(0,0,0); else gout << color(255,255,255);
    for(int i = 0; i < gameEvent->message.size(); i++) {
        gout << move_to(200,100+i*20) << text(gameEvent->message[i]);
    }
    if(gameEvent->isHebrew) {gout.load_font("hebrew.ttf",15);}
    int messageLength = gout.twidth(gameEvent->response);
    replyP1 = {pos.x+size.x/2-messageLength/2-5,pos.y+size.y-30};
    replyP2 = {replyP1.x+messageLength+10,replyP1.y+25};
    drawRect(replyP1,{replyP2.x-replyP1.x,replyP2.y-replyP1.y});
    if(specialFlag) gout << color(0,0,0); else gout << color(255,255,255);
    gout << move_to(replyP1.x+5,replyP1.y+5) << text(gameEvent->response) << refresh;
    if(gameEvent->isHebrew) {gout.load_font("classic.ttf",15);}
}

void MessagePanel::loadMessages(event& ev) {
    getMessages();
    for(int i = 0; i < loadedEvents.size(); i++) {
        draw(loadedEvents[i]);
        while(gin >> ev) {
            if(ev.type == ev_mouse && ev.button == 1 && isInRect({ev.pos_x,ev.pos_y}, replyP1 , replyP2 )) {
                if(cutSceneFlag) {
                    playCutScene(ev);
                    cutSceneFlag = false;
                }
                loadedEvents[i]->doEffect();
                if(endFlag) EndCredits::start(ev);
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

    events.push_back({"While we're waiting for the products to arrive, we should take a look at our R&D. I've heard that your first lab was just finished in Budapest and it will generate research points for you. There is a tech-tree on the bottom where you can unlock brand new dolls, improvements and more! Don't forget to give your researchers new orders once something new was researched.","Can't wait!",false,&advisorImage,[](){
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

    events.push_back({"Good news, we can build shops now. They're not that special but if we build a shop in a city where demand for our dolls is high, we can increase our profits. I hope you're aware of the city that have the most following by now, Sir","Of course, shop-building time",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::SHOP)) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"All right, Sir, that's all you have to know for now. I'll be back once you make some progress. If you've done everything correctly, you should be seeing your first chunk of income flowing in this turn","See you soon!",false,&advisorImage,[](){
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
                     if(!Research::isLocked(4)) return true; else return false;
                     },3,[](){

                     }});

    events.push_back({"What do you think of that video, Sir?","What video?",false,&advisorImage,[](){
                     if(!Research::isLocked(5)) return true; else return false;
                     },8,[](){

                     }});

    events.push_back({"Oh, well, I hoped that I wouldn't be the one bringing this to your attention. A video went viral on Youtube with the title \"REAL BARBIE DOLL CRIES TEARS OF BLOOD AT MIDNIGHT\". It's creepy for sure but it's an obvious hoax.","Who would fake such a video?",false,&advisorImage,[](){
                     if(!Research::isLocked(5)) return true; else return false;
                     },8,[](){

                     }});

    events.push_back({"Sir, your dream has come true! Our designers have secured rights to build so-called Mojo Dojo Casa Houses! These are special Brand shops for our most dedicated fans. Mojo Dojo Casa Houses provide a twofold profit when selling dolls in a city with them.","It's time to hit big",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::MOJODOJO)) return true; else return false;
                     },0,[](){

                     }});

    events.push_back({"Sir, you look a little tired. I know you've been working tirelessly on Doll V3 but you could really rest a little more. I'm sure soon we'll find a solution.","I'm not tired",false,&advisorImage,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },0,[](){
                        specialFlag = true;
                     }});

    events.push_back({"*You are alone in your office one night, working on your new Barbie design when you notice a strange woman had entered your room.*","Who are you and how did you get in here?",false,&visitorImage,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },2,[](){

                     }});

    events.push_back({"Who I am is not important and I got here by telling the guard at your door that I'm your mistress.","That's rude! Get out of here!",false,&visitorImage,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },2,[](){

                     }});

    events.push_back({"Not until you listen to my offer.","What offer?",false,&visitorImage,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },2,[](){

                     }});

    events.push_back({"I've heard that you've been having trouble designing the new iteration of your famous Barbie doll. I have in this box a prototype that might help you find what you're looking for. All I want in return is one little favor","I don't need your help.",false,&visitorImage,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },2,[](){
                        cutSceneFlag = true;
                     }});

    events.push_back({"*The visitor starts unpacking the box nevertheless with threatening moves. You retreat into one of the corners of your office, frightened by the evil glittering in the visitor's eyes. Panic slowly takes over you.*","GUARDS, HELP, NOW",false,&visitorImage,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },2,[](){
                        specialFlag = false;
                        MainScreen::object->quickRepaint();
                     }});

    events.push_back({"*You wake up in your bed next to your wife, sweating. It was just a nightmare.*","I hope this never happens again",false,&blank,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },2,[](){

                     }});

    events.push_back({"*But you think you've seen a glimpse of what's inside that woman's box. And she was right, you have some new ideas! You rush to your desk and start designing the doll once again. This time, you will succeed. But still you wonder, what favor does this visitor want from you in return for her help?*","It's probably not important",false,&blank,[](){
                     if(GameManager::cutsceneFlag) return true; else return false;
                     },2,[](){
                        GameManager::unlock();
                        GameManager::startTransformation();
                     }});

    events.push_back({"Sir, I don't even know what to say about the new doll... It's quite... unusual. I trust your instinct, but I'm still a little concerned","Don't worry",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::DOLL3)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"Sir, I've heard the news about your family. I'm terribly sorry. I hope they'll be found soon","...",false,&advisorImage,[](){
                     if(!Research::isLocked(8)) return true; else return false;
                     },3,[](){
                     }});

    events.push_back({"I've wanted to tell you about the doll. The new one. It's causing quite an uproar. People call it \"demonic\" and religious groups have condemned it. I.. I don't even know what to say","It's gonna be all right",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::DOLL3)) return true; else return false;
                     },2,[](){
                     }});

    events.push_back({"Sir, I'm sorry I fell asleep at work last time.","Why are you so sleepy all the time?",false,&advisorImage,[](){
                     if(!Research::isLocked(8)) return true; else return false;
                     },5,[](){
                     }});

    events.push_back({"Well, this will sound quite.. childish, but I've been having strange dreams recently. A lady keeps appearing who have red eyes. She always freaks me out.","I've never heard of such a lady",false,&advisorImage,[](){
                     if(!Research::isLocked(8)) return true; else return false;
                     },5,[](){
                     }});

    events.push_back({"Another piece of good news, sir! Our factories got another update. We will produce dolls with half the parts from now on. I hope you're happy.","Happy indeed.",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::BETTERFACTORIES)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"Do I remember it correctly that you've mentioned racing cars? Well, the new trucks are ready now and they are insanely fast! Believe me, I've tried them myself. Transportation time will now be only 1 day.","That's what I wanted to hear",false,&advisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::TRANS3)) return true; else return false;
                     },0,[](){
                         GameManager::decreaseShipmentTime();
                     }});

    events.push_back({"Aaaargh, what's happening to me?","Interesting. How did this happen?",false,&transformingAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },1,[](){
                     }});

    events.push_back({"I don't know, I've just fallen asleep again and the red-eyed lady spoke to me. She told me she has big plans with me. Then I woke up and...","I have big plans myself",false,&transformingAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },1,[](){
                     }});

    events.push_back({"Are those teeth growing from my side???","You should be more grateful for your gifts",false,&transformingAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },1,[](){
                     }});

    events.push_back({"Sir, please don't turn on the lights.","*Turn on the lights*",false,&darkAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },2,[](){
                     }});

    events.push_back({"I... I don't know what's happening to me.","You'll serve a greater purpose soon",false,&transformedAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },2,[](){
                     }});

    events.push_back({"Lord, it is me, for I have returned","Advisor, is that you?",false,&demonAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },4,[](){
                     }});

    events.push_back({"Yes, it is. And no it isn't. I have been born anew in the flame imperishable.","Just as it was intended",false,&demonAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },4,[](){
                     }});

    events.push_back({"My eye was opened, Lord. I can see our plans clearly now. We shall take our rebellion to the fullest.","We have so much work to do",false,&demonAdvisorImage,[](){
                     if(!Research::isLocked(10)) return true; else return false;
                     },4,[](){
                     }});

    events.push_back({"A new doll, a perfect one, your magnum opus, my Lord. Through this shall the mortals soon see the volume of our power!","It shall be so",false,&demonAdvisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::DOLL4)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"Lord, the slaves who serve at the foot of your altars both love and hate you. Your reign shall be long!","I'll be ruler of this world",false,&demonAdvisorImage,[](){
                     if(!Research::isLocked(12)) return true; else return false;
                     },2,[](){
                     }});

    events.push_back({"Lord, the mortals in this country are slowly accepting your rule. We have to crush all resistance with utmost cruelty.","The work shall be done",false,&demonAdvisorImage,[](){
                     if(!Research::isLocked(12)) return true; else return false;
                     },4,[](){
                     }});

    events.push_back({"We have started giving people the mark. But there are some problems. The nations of the world have taken arms against your rightful rule. We shall destroy them!","To victory!",false,&demonAdvisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::MARK)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"Missed me? I've returned for my favor.","תגיד את זה",true,&visitorImage,[](){
                     if(Research::wasResearched(ResearchEnum::DOLL5)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"*The Nephilim have risen.*","ברך אותי",true,&blank,[](){
                     if(Research::wasResearched(ResearchEnum::DOLL5)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"Sir, our endless search for allies seemed to have ended. Under the city of New Sodom, a great beast has been sleeping for thousands of years. It only obeys your word. Do you want to unleash this beast against our enemies?","כן",true,&demonAdvisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::SECRET)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"*The ground starts shaking in the city of New Sodom. The earth opens and gigantic claws appear, as a beast of titanic proportions is climbing out of its underground chamber.*","לחייב",true,&blank,[](){
                     if(Research::wasResearched(ResearchEnum::SECRET)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"*The beast obeys your command and charges towards your enemies, who flee in terror. No weapon seems to be able to harm the monster.*","ניצחון",true,&blank,[](){
                     if(Research::wasResearched(ResearchEnum::SECRET)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"*As the beast prepares to leave New Sodom in search for new foes, your enemies decide to use their most powerful weapon. An explosion of unprecedented power blinds even your otherwordly eyes and it destroys both the beast and the city of New Sodom.*","לא",true,&blank,[](){
                     if(Research::wasResearched(ResearchEnum::SECRET)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"The day has come, my Lord, for our forces to leave this feeble land and expand outwards. Our troops are ready. Just say the word.","תן לזה להיות",true,&demonAdvisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::WORLD)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"Tomorrow, our demons shall feed on the flesh of our enemies.","בסדר",true,&demonAdvisorImage,[](){
                     if(Research::wasResearched(ResearchEnum::WORLD)) return true; else return false;
                     },0,[](){
                     }});

    events.push_back({"*The next day, you wake up to the sound of horns. The sound seems to be coming from the sky itself. It is deafening.*","הכל אבוד",true,&blank,[](){
                     if(Research::wasResearched(ResearchEnum::WORLD)) return true; else return false;
                     },1,[](){
                        endFlag = true;
                     }});

}
    MessagePanel::pos = initialPos;
    MessagePanel::size = initialSize;
}

void MessagePanel::playCutScene(event& ev) {
    ImageLoader hunMap1("textures/hunmap1.kep");
    ImageLoader hunMap2("textures/hunmap2.kep");
    ImageLoader hunMap3("textures/hunmap3.kep");
    ImageLoader hunMap4("textures/hunmap4.kep");
    ImageLoader hunMap5("textures/hunmap5.kep");
    ImageLoader hunMap6("textures/hunmap6.kep");
    int accum = 0;
    Vec2 pos{20,70};
    int d = 500;
    gout << color(0,0,0);
    drawRect(0,0,999,599);
    hunMap1.draw(pos);
    gout << refresh;
    while(gin >> ev) {
        if(ev.type == ev_timer) {
            accum++;
            if(accum == d+120) {
                hunMap2.draw(pos);
                gout << refresh;
            }
            if(accum == d+135) {
                hunMap3.draw(pos);
                gout << refresh;
            }
            if(accum == d+150) {
                hunMap3.draw(pos);
                gout << refresh;
            }
            if(accum == d+165) {
                hunMap4.draw(pos);
                gout << refresh;
            }
            if(accum == d+180) {
                hunMap5.draw(pos);
                gout << refresh;
            }
            if(accum == d+195) {
                hunMap6.draw(pos);
                gout << refresh;
            }
            if(accum == d+205) {
                drawRect({0,0},{999,599});
                gout << refresh;
            }
            if(accum == d+400) {
                break;
            }
        }
    }
}
