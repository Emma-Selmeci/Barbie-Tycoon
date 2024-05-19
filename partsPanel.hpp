#ifndef PARTSPANEL.HPP
#define PARTSPANEL.HPP

#include "graphics.hpp"

#include "subPanel.hpp"
#include "city.hpp"
#include "slider.hpp"
#include "textWidget.hpp"
#include "button.hpp"

using namespace genv;

class PartsPanel : public SubPanel {
private:
    Slider partSlider;
    static Slider* sliderp;
    TextWidget storedParts;
    TextWidget arrivingParts;
    TextWidget purchasePlease;
    Button confirmButton;
    TextWidget noFactoryButton;
    static void buttonPressed(int);
public:
    PartsPanel();
    void draw() override;
    void refresh(City*) override;
    void update(event&) override;
};

#endif // PARTSPANEL
