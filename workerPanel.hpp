#ifndef WORKERPANEL.HPP
#define WORKERPANEL.HPP

#include "subPanel.hpp"
#include "textWidget.hpp"
#include "button.hpp"

class WorkerPanel : public SubPanel {
    TextWidget status;
    TextWidget fanWidget;
    Button increasePayment;
    TextWidget marketingWidget;
    Button marketingButton;
    static void buttonCB(int);
public:
    WorkerPanel();
    void draw() override;
    void refresh(City*) override;
    void update(event&) override;

};

#endif // WORKERPANEL
