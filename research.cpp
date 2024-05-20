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
    Research("Better","dolls",120),
    Research("Shops","",120),
    Research("Lvl 2","trucks",140),
    Research("Marketing","",140),
    Research("More","factories",200),
    Research("More","research",200),
    Research("Advanced","dolls",240),
    Research("Barbie","shops",240),
    Research("Efficient","factories",260),
    Research("Lvl3","trucks",260),
    Research("The perfect","doll",300),
    Research("Mark of","the beast",300),
    Research("Final doll","",340),
    Research("Secret","weapon",340),
    Research("World","conquest",400)
};

Research* Research::currentTech = &techList[0];
