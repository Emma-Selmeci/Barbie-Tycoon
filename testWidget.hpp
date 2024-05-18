#ifndef TESTWIDGET.HPP
#define TESTWIDGET.HPP

#include "graphics.hpp"

#include "widget.hpp"

using namespace genv;

class TestWidget : public Widget {
public:
    TestWidget(Vec2);
    virtual void draw();
    virtual void drop();
    virtual bool check(event&);
    virtual bool update(event&);
};

#endif // TESTWIDGET


