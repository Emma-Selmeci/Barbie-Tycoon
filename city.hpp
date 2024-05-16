#ifndef CITY.HPP
#define CITY.HPP

#include <string>

class RightPanel;

class City {
    City(std::string); //Exciting private constructor
    std::string name;
public:
    static City cities[10];
    friend class RightPanel;
};

#endif // CITY
