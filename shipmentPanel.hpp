#ifndef SHIPMENTPANEL.HPP
#define SHIPMENTPANEL.HPP

#include "subPanel.hpp"
#include "textWidget.hpp"
#include "selector.hpp"
#include "slider.hpp"
#include "button.hpp"

class ShipmentPanel : public SubPanel {
    TextWidget dollsHere;
    TextWidget whereToShip;
    Selector selectDoll;
    Selector selectCity;
    Slider amountSlider;
    TextWidget statusText;
    Button confirmButton;
    static Selector* selectDollP;
    static Selector* selectCityP;
    static Slider* amountSliderP;
    static void selectorCB(int,int);
    static void buttonCB(int);
public:
    ShipmentPanel();
    void draw() override;
    void refresh(City*) override;
    void update(event&) override;
};

#endif // SHIPMENTPANEL
