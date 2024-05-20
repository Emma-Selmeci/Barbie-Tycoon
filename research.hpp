#ifndef RESEARCH.HPP
#define RESEARCH.HPP

#include <string>

class TechTree;

enum ResearchEnum {
    DOLL2,
    SHOP,
    TRANS2,
    MARKETING,
    MOREFACTORIES,
    MORERESEARCH,
    DOLL3,
    MOJODOJO,
    BETTERFACTORIES,
    TRANS3,
    DOLL4,
    MARK,
    DOLL5,
    SECRET,
    WORLD,
};

class Research {
    static int idCounter;
    int id;
    int researchAccum = 0;
    std::string name1; //I'm so sorry
    std::string name2;
    static Research techList[15];
    int researchCost;
    bool isResearched = false;

    bool isLocked();
    Research(std::string name1, std::string name2, int cost);
public:
    static bool isLocked(int);
    static Research* currentTech;
    static bool wasResearched(Research*);
    static bool wasResearched(ResearchEnum);
    static void checkUnlock();
    friend class TechTree;
    friend class GameManager;
};

#endif // RESEARCH
