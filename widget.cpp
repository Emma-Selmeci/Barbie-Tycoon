#include "widget.hpp"

Widget::Widget(Vec2 pos) : pos({pos.x,pos.y}) {}

void Widget::rePos(Vec2 newPos) {
    pos.x+=newPos.x;
    pos.y+=newPos.y;
}
