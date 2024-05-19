#ifndef SHIPMENTPANEL.HPP
#define SHIPMENTPANEL.HPP

#include "subPanel.hpp"
#include "textWidget.hpp"
#include "selector.hpp"
#include "slider.hpp"

class ShipmentPanel : public SubPanel {
    TextWidget dollsHere;
    TextWidget whereToShip;
    Selector selectDoll;
    Selector selectCity;
    Slider amountSlider;
    TextWidget statusText;
    Button confirmButton;
    static void selectorCB(int,int);
public:
    ShipmentPanel();
    void draw() override;
    void refresh(City*) override;
    void update(event&) override;
};

#endif // SHIPMENTPANEL
