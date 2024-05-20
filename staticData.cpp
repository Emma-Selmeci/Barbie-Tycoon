#include "staticData.hpp"

#include <iostream>

ImageLoader StaticData::leftArrow("textures/leftArrow.kep");
ImageLoader StaticData::rightArrow("textures/rightArrow.kep");
ImageLoader StaticData::downArrow("textures/downArrow.kep");
ImageLoader StaticData::upArrow("textures/upArrow.kep");

int StaticData::dollToParts(int dollNum) {
    switch(dollNum) {
        case 0 : {return 2;}
        case 1 : {return 3;}
        case 2 : {return 5;}
        case 3 : {return 10;}
        case 4 : {return 20;}
    }
    std::cout << "Error at dollToParts()!\n";
    return 0;
}

std::string StaticData::dollToName(int dollNum) {
    switch(dollNum) {
        case 0 : {return "Simple Doll";}
        case 1 : {return "Advanced Doll";}
        case 2 : {return "Eerie Doll";}
        case 3 : {return "Demonic Doll";}
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
