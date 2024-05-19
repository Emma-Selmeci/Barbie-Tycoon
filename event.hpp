#ifndef EVENT.HPP
#define EVENT.HPP

#include <functional>
#include <vector>

#include "imageLoader.hpp"

/*
This class is responsible for the numerous messages that pop up at the beginning of each turn
*/

class Event {
std::vector<std::string> message;
std::string response;
bool isHebrew; //This is where the fun begins
ImageLoader* image;
std::function<bool()> f;
int turnDelay;
void cropMessage(std::string&);
public:
    Event(std::string str, std::string response, bool isHebrew, ImageLoader* image, std::function<bool()> f, int turnDelay);
};

#endif // EVENT
