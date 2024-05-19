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
    friend class RightPanel;
    int storedParts = 0;
    int shippingParts = 0;
    int producingDolls = 0;
    int producedType = 0;
    int storedDolls[5] = {
        0,0,0,0,0
    };
    bool hasFactory = false;
};

#endif // CITY
