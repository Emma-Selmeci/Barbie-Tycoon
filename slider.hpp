#ifndef SLIDER.HPP
#define SLIDER.HPP

#include "widget.hpp"

class Slider : public Widget {
private:
    int min, max, value;
    bool mouseClicked(event&);
    void boundValue();
    bool pressed = false;
public:
    Slider(Vec2, int, int);
    void resetValues(int, int);
    void draw();
    void drop();
    bool check(event&);
    bool update(event&);
};

#endif // SLIDER
