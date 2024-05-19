#include "city.hpp"

#include <iostream>

//The reason this method is not used more is that it was added late in development
std::string City::cityToName(int i) {
    switch(i) {
        case 0 : return "Gyor";
        case 1 : return "Szfvar";
        case 2 : return "Budapest";
        case 3 : return "Szhely";
        case 4 : return "Pecs";
        case 5 : return "Szeged";
        case 6 : return "Szolnok";
        case 7 : return "Miskolc";
        case 8 : return "Debrecen";
        case 9 : return "Bekes";
    }
    std::cout << "Something went horribly wrong in cityToName()";
    return "I think Python is an effective programming language"; //It would be really embarassing if this popped up during testing!
}

City::City(std::string cityName) : name(cityName) {

}

City City::cities[10] = {
    City("Gyor"),
    City("Szfvar"),
    City("Budapest"),
    City("Szhely"),
    City("Pecs"),
    City("Szeged"),
    City("Szolnok"),
    City("Miskolc"),
    City("Debrecen"),
    City("Bekes"),
};
