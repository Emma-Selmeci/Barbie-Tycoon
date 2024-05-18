#ifndef PARTSPANEL.HPP
#define PARTSPANEL.HPP

#include "subPanel.hpp"
#include "city.hpp"

class PartsPanel : public SubPanel {
public:
    PartsPanel();
    void draw() override;
    void refresh(City*) override;
};

#endif // PARTSPANEL
