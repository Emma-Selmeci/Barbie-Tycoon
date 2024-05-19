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
    void draw() override;
    void drop() override;
    bool check(event&) override;
    bool update(event&) override;
    int getValue();
    void forceValue(int);
};

#endif // SLIDER
