#ifndef GAMEMANAGER.HPP
#define GAMEMANAGER.HPP

#include "city.hpp"

class GameManager {
public:
    static int money;
    static int turnCounter;
    static void purchaseParts(City*, int);
    static void nextTurn();
    static void requestRefresh();
    static void produceDolls(City*, int, int);
};

#endif // GAMEMANAGER
