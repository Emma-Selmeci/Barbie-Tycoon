#ifndef PRODUCTIONPANEL.HPP
#define PRODUCTIONPANEL.HPP

#include "subPanel.hpp"

class ProductionPanel : public SubPanel {
public:
    ProductionPanel();
    void draw() override;
    void refresh(City*) override;
    void update(event&) override;
};


#endif // PRODUCTIONPANEL
