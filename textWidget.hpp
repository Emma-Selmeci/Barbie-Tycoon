#ifndef TEXTWIDGET.HPP
#define TEXTWIDGET.HPP

#include <vector>

#include "widget.hpp"

class TextWidget : public Widget {
std::vector<std::string> message;
void cropMessage(std::string&);
public:
    TextWidget(Vec2, std::string);
    void draw() override;
    void drop() override;
    bool check(event&) override;
    bool update(event&) override;
    void updateMessage(std::string&);
};

#endif // TEXTWIDHET
