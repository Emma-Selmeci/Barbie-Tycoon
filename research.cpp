#include "research.hpp"

#include <iostream>

int Research::idCounter = 0;

bool Research::wasResearched(ResearchEnum tech) {
    return techList[tech].isResearched;
}

Research::Research(std::string name1,std::string name2, int cost) : name1(name1), name2(name2), researchCost(cost) {id = idCounter++;}

bool Research::isLocked(int techNum) {
    for(int i = 0; i < techNum - techNum%2; i++) {
        if(!techList[i].isResearched) return true;
    }
    return false;
}

bool Research::isLocked() {
    return isLocked(id);
}

bool Research::isItOurCurrentTech() {
    std::cout << "Flag\n";
    if(currentTech == &techList[6]) return true; else return false;
}

void Research::checkUnlock() {
    if(currentTech->researchAccum >= currentTech->researchCost) currentTech->isResearched = true;
}

void Research::unlock() {
    techList[6].isResearched = true;
}

Research Research::techList[15] = {
    Research("Better","dolls",160),
    Research("Shops","",160),
    Research("Lvl 2","trucks",200),
    Research("Marketing","",200),
    Research("More","factories",240),
    Research("More","research",240),
    Research("Advanced","dolls",300),
    Research("Barbie","shops",300),
    Research("Efficient","factories",340),
    Research("Lvl3","trucks",340),
    Research("The perfect","doll",400),
    Research("Mark of","the beast",400),
    Research("Final doll","",600),
    Research("Secret","",600),
    Research("World","conquest",1000)
};

Research* Research::currentTech = &techList[0];
