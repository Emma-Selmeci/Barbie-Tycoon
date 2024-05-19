#include "city.hpp"

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
