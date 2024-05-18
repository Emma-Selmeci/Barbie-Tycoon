#ifndef CITY.HPP
#define CITY.HPP

#include <string>

class RightPanel;

class City {
    City(std::string); //Exciting private constructor
    std::string name;
public: //I'm leaving most of these public for easier access...
    static City cities[10];
    friend class RightPanel;
    int storedParts = 0;
};

#endif // CITY
