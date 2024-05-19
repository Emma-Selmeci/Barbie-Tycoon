#ifndef GAMEMANAGER.HPP
#define GAMEMANAGER.HPP

#include "city.hpp"

class GameManager {
public:
    static int money;
    static int turnCounter;
    static void purchaseParts(City*, int);
};

#endif // GAMEMANAGER
