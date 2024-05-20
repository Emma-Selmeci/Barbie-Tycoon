#include "research.hpp"

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

void Research::checkUnlock() {
    if(currentTech->researchAccum >= currentTech->researchCost) currentTech->isResearched = true;
}

Research Research::techList[15] = {
    Research("Better","dolls",100),
    Research("Shops","",100),
    Research("Lvl 2","trucks",160),
    Research("Marketing","",160),
    Research("More","factories",200),
    Research("More","research",200),
    Research("Advanced","dolls",260),
    Research("Barbie","shops",260),
    Research("Efficient","factories",300),
    Research("Lvl3","trucks",300),
    Research("The perfect","doll",340),
    Research("Mark of","the beast",340),
    Research("Final doll","",400),
    Research("Secret","",400),
    Research("World","conquest",600)
};

Research* Research::currentTech = &techList[0];
