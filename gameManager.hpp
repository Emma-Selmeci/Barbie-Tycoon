#ifndef GAMEMANAGER.HPP
#define GAMEMANAGER.HPP

#include "city.hpp"

class GameManager {
    static void generateFans();
    static void generateStrike();
    static void ship(City&);
    static int fanCities[10];
public:
    static int money;
    static int turnCounter;
    static int shipmentTime;
    static int eventAccum;
    static int transformationCoefficient;
    static bool cutsceneFlag;
    static bool transformationFlag;
    static void purchaseParts(City*, int);
    static void shipDolls(City* from, int to, int type, int amount);
    static void nextTurn();
    static void requestRefresh();
    static void produceDolls(City*, int, int);
    static void increaseWages(City*);
    static void changeActiveTech(int techNum);
    static void buildLab(City*);
    static void forceStrike(City*);
    static void buildShop(City*);
    static void decreaseShipmentTime();
    static void doMarketing(City*);
    static void buildFactory(City*);
    static void buildLabAndPay(City*);
    static void unlock();
    static void startTransformation();
};

#endif // GAMEMANAGER
