#ifndef MESSAGEPANEL.HPP
#define MESSAGEPANEL.HPP

#include "imageLoader.hpp"
#include "helpers.hpp"

//Trying my luck with an entirely static class this time!

class MessagePanel {
    static ImageLoader advisorImage;
    static Vec2 pos;
    static Vec2 size;
    static Vec2 replyP1;
    static Vec2 replyP2;
public:
    static void setPos(Vec2, Vec2);
    static void draw();
    static void loadMessages(event&);
};

#endif // MESSAGEPANEL
