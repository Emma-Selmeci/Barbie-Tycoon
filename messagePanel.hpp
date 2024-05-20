#ifndef MESSAGEPANEL.HPP
#define MESSAGEPANEL.HPP

#include <vector>

#include "imageLoader.hpp"
#include "helpers.hpp"
#include "event.hpp"

//Trying my luck with an entirely static class this time!

class MessagePanel {
    static ImageLoader advisorImage;
    static ImageLoader visitorImage;
    static ImageLoader transformingAdvisorImage;
    static ImageLoader transformedAdvisorImage;
    static ImageLoader darkAdvisorImage;
    static ImageLoader demonAdvisorImage;
    static ImageLoader blank;
    static Vec2 pos;
    static Vec2 size;
    static Vec2 replyP1;
    static Vec2 replyP2;
    static std::vector<GameEvent> events;
    static std::vector<GameEvent*> loadedEvents;
    static void getMessages();
    static bool specialFlag;
    static bool endFlag;
    static bool cutSceneFlag;
    static void playCutScene(event& ev);
public:
    static void setPos(Vec2, Vec2);
    static void draw(GameEvent*);
    static void loadMessages(event&);

};

#endif // MESSAGEPANEL
