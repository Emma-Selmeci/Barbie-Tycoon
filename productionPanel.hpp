#ifndef PRODUCTIONPANEL.HPP
#define PRODUCTIONPANEL.HPP

#include "subPanel.hpp"
#include "selector.hpp"
#include "slider.hpp"
#include "textWidget.hpp"
#include "button.hpp"

class ProductionPanel : public SubPanel {
    TextWidget noFactory;
    TextWidget chooseWhatToProduce;
    TextWidget dollPrice;
    Slider amountSlider;
    TextWidget partsHere;
    Selector selectDoll;
    TextWidget orderedDolls;
    Button produceButton;
    Button buildButton;
    static Slider* amountSliderP;
    static Selector* selectDollP;
    static void buttonPressed(int);
    static void selectorChange(int, int);
public:
    ProductionPanel();
    void draw() override;
    void refresh(City*) override;
    void update(event&) override;
};


#endif // PRODUCTIONPANEL
