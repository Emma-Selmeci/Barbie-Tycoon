#ifndef WIDGET.HPP
#define WIDGET.HPP

#include "graphics.hpp"

#include "helpers.hpp"

using namespace genv;

class Widget {
protected:
    Vec2 pos;
public:
    bool isActive = true;
    Widget(Vec2);
    virtual void draw() = 0;
    virtual void drop() = 0;
    virtual bool check(event&) = 0;
    virtual bool update(event&) = 0;
    void rePos(Vec2);
};

#endif // WIDGET
