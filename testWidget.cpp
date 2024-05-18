#include "testWidget.hpp"

TestWidget::TestWidget(Vec2 pos) : Widget(pos) {
}

void TestWidget::draw() {
    gout << color(0,0,0) << move_to(pos.x, pos.y) << box(100,100);
}


void TestWidget::drop() {}
bool TestWidget::check(event& ev) {return false;}
bool TestWidget::update(event& ev) {return false;}
