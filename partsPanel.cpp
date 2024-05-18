#include "partsPanel.hpp"

#include "graphics.hpp"

#include "testWidget.hpp"
#include "slider.hpp"

using namespace genv;

PartsPanel::PartsPanel() {
    Widget* w2 = new Slider({0,40},0,10);
    addWidget(w2);
}

void PartsPanel::draw() {
    SubPanel::draw();
    gout << move_to(pos.x+5, pos.y+5) << text("Purchase parts!") << move_to(pos.x+5, pos.y+20) << text("10$ each");
}

void PartsPanel::refresh(City* city) {
}
