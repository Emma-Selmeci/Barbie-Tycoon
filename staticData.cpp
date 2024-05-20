#include "staticData.hpp"

#include <iostream>

#include "gameManager.hpp"
#include "research.hpp"

ImageLoader StaticData::leftArrow("textures/leftArrow.kep");
ImageLoader StaticData::rightArrow("textures/rightArrow.kep");
ImageLoader StaticData::downArrow("textures/downArrow.kep");
ImageLoader StaticData::upArrow("textures/upArrow.kep");

int StaticData::dollToParts(int dollNum) {
    int coefficient = Research::wasResearched(ResearchEnum::BETTERFACTORIES) ? 2 : 1;
    switch(dollNum) {
        case 0 : {return 2/coefficient;}
        case 1 : {return 3/coefficient;}
        case 2 : {return 5/coefficient;}
        case 3 : {return 10/coefficient;}
        case 4 : {return 20/coefficient;}
    }
    std::cout << "Error at dollToParts()!\n";
    return 0;
}

std::string StaticData::dollToName(int dollNum) {
    switch(dollNum) {
        case 0 : {return GameManager::transformationCoefficient > 15 ? "Imp" : "Simple Doll";}
        case 1 : {return GameManager::transformationCoefficient > 15 ? "Lesser demon" : "Advanced Doll";}
        case 2 : {return GameManager::transformationCoefficient > 15 ? "Sinner demon" : "Eerie Doll";}
        case 3 : {return GameManager::transformationCoefficient > 15 ? "Fallen demon" : "Demonic Doll";}
        case 4 : {return "Nephilim";}
    }
    std::cout << "Error at dollToParts()!\n";
    return 0;
}

int StaticData::dollToPrice(int dollNum) {
    switch(dollNum) {
        case 0 : {return 35;}
        case 1 : {return 70;}
        case 2 : {return 140;}
        case 3 : {return 260;}
        case 4 : {return 460;}
    }
    std::cout << "Error at dollToPrice()!\n";
    return 0;
}
