#ifndef EVENT.HPP
#define EVENT.HPP

#include <functional>
#include <vector>

#include "imageLoader.hpp"

class MessagePanel;

/*
This class is responsible for the numerous messages that pop up at the beginning of each turn
*/

class GameEvent {
std::vector<std::string> message;
std::string response;
bool isHebrew; //This is where the fun begins
bool wasSelected = false;
ImageLoader* image;
std::function<bool()> f;
int turnDelay;
std::function<void()> effect;
void cropMessage(std::string&);
public:
    GameEvent(std::string str, std::string response, bool isHebrew, ImageLoader* image, std::function<bool()> f, int turnDelay, std::function<void()> effect);
    bool check();
    void doEffect();
    friend class MessagePanel;
};

#endif // EVENT
