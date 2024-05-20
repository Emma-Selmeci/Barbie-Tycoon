#ifndef CITY.HPP
#define CITY.HPP

#include <string>

#include "staticData.hpp"

class RightPanel;

class City {
    City(std::string); //Exciting private constructor
    std::string name;
public: //I'm leaving most of these public for easier access...
    static City cities[10];
    static std::string cityToName(int);
    std::string getName();
    friend class RightPanel;
    bool shippedThisTurn = false;
    int wages = 100;
    int storedParts = 0;
    int shippingParts = 0;
    int producingDolls = 0;
    int producedType = 0;
    int marketingBonus = 0;
    int storedDolls[5] = {
        0,0,0,0,0
    };
    //I know this could've been done in a more elegant manner but I want my code to stay readable
    int shippedDolls1[5] = {
        0,0,0,0,0
    };
    int shippedDolls2[5] = {
        0,0,0,0,0
    };
    int shippedDolls3[5] = {
        0,0,0,0,0
    };
    int fans[5] = {
        0,0,0,0,0
    };
    bool hasFactory = false;
    bool hasLab = false;
    int shopLevel = 0;
    bool hasStrike = false;
};

#endif // CITY
