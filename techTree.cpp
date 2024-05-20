#include "techTree.hpp"

#include "staticData.hpp"
#include "helpers.hpp"
#include "colors.hpp"
#include "graphicsHelper.hpp"
#include "gameManager.hpp"

Vec2 TechTree::pos, TechTree::size;
int TechTree::currentPos = 0;
Vec2 TechTree::sub;

void TechTree::update(event& ev) {
    if(!(ev.type == ev_mouse && ev.button == 1)) return; //Linear algebra is useful for once
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+40,pos.y+5,pos.x+40+sub.x-10,pos.y+sub.y)) {
        if(!Research::isLocked(currentPos*2)) GameManager::changeActiveTech(currentPos*2);
        draw();
        return;
    }
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+40+sub.x,pos.y+5,pos.x+40+2*sub.x-10,pos.y+sub.y)) {
        if(!Research::isLocked(currentPos*2+1)) GameManager::changeActiveTech(currentPos*2+1);
        draw();
        return;
    }
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+3,pos.y+3,pos.x+33,pos.y+33)) {
        currentPos--;
        boundValue();
        draw();
        return;
    }
    if(isInRect(ev.pos_x,ev.pos_y,pos.x+3,pos.y+size.y-32,pos.x+33,pos.y+size.y-2)) {
        currentPos++;
        boundValue();
        draw();
        return;
    }

}

void TechTree::boundValue() {
    if(currentPos < 0) currentPos = 0; else if(currentPos > 7) currentPos = 7;
}

void TechTree::setDim(Vec2 newPos, Vec2 newSize) {


    pos = newPos; size = newSize;
    sub.x = (size.x - 40) / 3;
    sub.y = size.y-10;
}

void TechTree::drawTech(Research* tech, bool onLeft) {

    std::string t1 = tech->isLocked() ? "Research" : tech->name1;
    std::string t2 = tech->isLocked() ? "Locked" : tech->name2;

    if(tech->isResearched) {

        onLeft ? drawSpecialRect(pos.x+40,pos.y+5,sub.x-10,sub.y,GUIvioletDark,GUIvioletLight) : drawSpecialRect(pos.x+40+sub.x,pos.y+5,sub.x-10,sub.y,GUIvioletDark,GUIvioletLight);
        gout << color(0,0,0);
        onLeft ? gout << move_to(pos.x+42,pos.y+sub.y/2-10) : gout << move_to(pos.x+sub.x+42,pos.y+sub.y/2-10);
        gout << text(t1);
        onLeft ? gout << move_to(pos.x+42,pos.y+sub.y/2+10) : gout << move_to(pos.x+sub.x+42,pos.y+sub.y/2+10);
        gout << text(t2);
    } else {
        onLeft ? drawSpecialRect(pos.x+40,pos.y+5,sub.x-10,sub.y,0,0,0,255,255,255) : drawSpecialRect(pos.x+40+sub.x,pos.y+5,sub.x-10,sub.y,0,0,0,255,255,255);
        gout << color(0,0,0);
        onLeft ? gout << move_to(pos.x+42,pos.y+sub.y/2-10) : gout << move_to(pos.x+sub.x+42,pos.y+sub.y/2-10);
        gout << text(t1);
        onLeft ? gout << move_to(pos.x+42,pos.y+sub.y/2+10) : gout << move_to(pos.x+sub.x+42,pos.y+sub.y/2+10);
        gout << text(t2);
    }
}

void TechTree::draw() {
    gout << color(lightPink);
    drawRect(pos,size);
    StaticData::upArrow.draw({pos.x+3,pos.y+3});
    StaticData::downArrow.draw({pos.x+3, pos.y+size.y-32});
    if(currentPos > 6) {
            drawTech(&Research::techList[14],true);
    } else {
            drawTech(&Research::techList[currentPos*2],true);
            drawTech(&Research::techList[currentPos*2+1],false);
    }


    gout << move_to(pos.x+sub.x*2.5-gout.twidth("Researching:")/2+30,pos.y+2) << text("Researching:");
    gout << move_to(pos.x+sub.x*2.5-gout.twidth(Research::currentTech->name1)/2+30,pos.y+19) << text(Research::currentTech->name1);
    gout << move_to(pos.x+sub.x*2.5-gout.twidth(Research::currentTech->name2)/2+30,pos.y+36) << text(Research::currentTech->name2);
    std::string t = std::to_string(Research::currentTech->researchAccum) + "/" + std::to_string(Research::currentTech->researchCost);
    gout << move_to(pos.x+sub.x*2.5-gout.twidth(t)/2+30,pos.y+53) << text(t);


}
