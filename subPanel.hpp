#ifndef SUBPANEL.HPP
#define SUBPANEL.HPP

#include <vector>

#include "graphics.hpp"

#include "helpers.hpp"
#include "widget.hpp"
#include "city.hpp"

using namespace genv;

class SubPanel { //Where are doms when you need them?
private:
    void checkAllWidgets(event&);
    void drawWidgets();
protected:
    static Vec2 pos;
    std::vector<Widget*> widgets;
    Widget* focusedWidget = 0;
    static City* currentCity;
public:
    virtual void draw();
    virtual void addWidget(Widget*) final;
    virtual void update(event&);
    virtual void refresh(City*);
    static void setPos(Vec2);
    void updatePos();
};

#endif // SUBPANEL
