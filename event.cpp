#include "event.hpp"

#include "mainScreen.hpp"

static int messageWidth = 400;

GameEvent::GameEvent(std::string str, std::string response, bool isHebrew, ImageLoader* image, std::function<bool()> f, int turnDelay, std::function<void()> effect) :
    response(response), isHebrew(isHebrew), image(image), f(f), turnDelay(turnDelay), effect(effect)
    {
    static bool isInitialized = false;
    if(!isInitialized) {
        gout.load_font("classic.ttf",15);
        isInitialized = true;
    }
    cropMessage(str);
}

bool GameEvent::check() {
    if(wasSelected) return false;
    if(f()) {
        if(turnDelay == 0) {
                wasSelected = true;
                return true;
        }else turnDelay--;
    }
    return false;
}

void GameEvent::doEffect() {
    effect();
}

void GameEvent::cropMessage(std::string& str) {
    int lock = 0;

    for(int i = 1; i < str.length()+1; i++) {
        if(i == str.length()) {
            message.push_back(str.substr(lock,i-lock));
            break;
        }

        if(gout.twidth(str.substr(lock,i-lock)) > messageWidth) {
            for(int j = i; j > 0; j--) {
                if(str[j] == ' ') {
                    message.push_back(str.substr(lock,j-lock));
                    lock = j+1;
                    i = j+1;
                    break;
                }
            }
        }
    }
}
