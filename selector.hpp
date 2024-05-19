#ifndef SELECTOR.HPP
#define SELECTOR.HPP

#include "widget.hpp"
#include <vector>

typedef void (*selectorCallback)(int, int);

enum SelectorType {
    CITYSELECTOR,
    DOLLSELECTOR,
};

class Selector : public Widget {
    selectorCallback f;
    int value = 0;
    SelectorType type;
    static std::string barbieTypes[5];
    void boundValue();
    int id;
public:
    Selector(Vec2 pos, SelectorType, selectorCallback, int id);
    virtual void draw();
    virtual void drop();
    virtual bool check(event&);
    virtual bool update(event&);
    void forceSelection(int);
    int getValue();
};

#endif // SELECTOR
