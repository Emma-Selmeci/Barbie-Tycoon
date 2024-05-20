#include "textWidget.hpp"

#include "mainScreen.hpp"

TextWidget::TextWidget(Vec2 pos, std::string str) : Widget(pos) {
    static bool wasInitialized = false;
    if(!wasInitialized) {
        gout.load_font("classic.ttf",15);
        wasInitialized = true;
    }
    cropMessage(str);
}

void TextWidget::cropMessage(std::string& str) {
    message.clear();
    int lock = 0;

    for(int i = 1; i < str.length()+1; i++) {
        if(i == str.length()) {
            message.push_back(str.substr(lock,i-lock));
            break;
        }

        if(gout.twidth(str.substr(lock,i-lock)) > MainScreen::rightWidth-10) {
            for(int j = i; j > 0; j--) {
                if(str[j] == ' ') {
                    message.push_back(str.substr(lock,j-lock));
                    lock = j+1;
                    i = j+1;
                    break;
                }
            }
        }
    }
}

void TextWidget::draw() {
    for(int i = 0; i < message.size(); i++) {
        gout << move_to(pos.x,pos.y+i*15) << text(message[i]);
    }
}

void TextWidget::updateMessage(std::string& str) {
    cropMessage(str);
}

void TextWidget::drop() {}
bool TextWidget::check(event& ev) {return false;}
bool TextWidget::update(event& ev) {return false;}
