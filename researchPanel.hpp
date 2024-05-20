#ifndef RESEARCHPANEL.HPP
#define RESEARCHPANEL.HPP

#include "subPanel.hpp"
#include "textWidget.hpp"
#include "button.hpp"

class ResearchPanel : public SubPanel {
    TextWidget statusWidget;
    TextWidget budapestWidget;
    TextWidget shopWidget;
    TextWidget labWidget;
    Button enterButton;
    Button shopButton;
    Button labButton;
    static void buttonCB(int);
    static bool specialEvent;
public:
    ResearchPanel();
    void draw() override;
    void refresh(City*) override;
    void update(event&) override;
};

#endif // RESEARCHPANEL
