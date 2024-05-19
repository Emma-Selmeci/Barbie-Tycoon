#ifndef BUTTON.HPP
#define BUTTON.HPP

#include "widget.hpp"

typedef void (*buttonCallback)(int); //Using a function pointer for the first time in my life!

class Button : public Widget {
    int id;
    buttonCallback cb;
    std::string message;
    int textLength;
public:
    Button(Vec2, int, buttonCallback, std::string);
    void draw() override;
    void drop() override;
    bool check(event&) override;
    bool update(event&) override;
};

#endif // BUTTON
