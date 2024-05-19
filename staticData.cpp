#include "staticData.hpp"

#include <iostream>

ImageLoader StaticData::leftArrow("textures/leftArrow.kep");
ImageLoader StaticData::rightArrow("textures/rightArrow.kep");

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
