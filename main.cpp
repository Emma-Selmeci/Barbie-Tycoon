#include <iostream>
#include <functional>
#include <vector>

#include "graphics.hpp"

#include "imageLoader.hpp"
#include "mainMenu.hpp"

using namespace genv;

class FunctorClass {
    public:
    std::function<bool()> _f;
    FunctorClass(std::function<bool()> f) : _f(f) {}
    bool getResult() {
        return _f();
    }
};

bool testMethod() {
return true;
}

int main()
{
    std::vector<FunctorClass> functorclasses;
    functorclasses.push_back({[](){
                             std::cout << "Called\n";
                             return true;
                             }});
    functorclasses[0].getResult();
    std::vector<FunctorClass*> other;
    other.push_back(&functorclasses[0]);
    other[0]->getResult();
    other.clear();
    functorclasses[0].getResult();



    /*
    So, as it turns out, there IS a difference between Java and C++ initialization order.
    In Java, static members are initialized when the class is first acessed.
    In C++, static members are initialized when the program starts. This was the reason that i got wrong results with gout.twidth();
    This was a *very* frustrating problem to solve.
    */


    gout.open(1000,600);
    gout << move_to(200,200) << text("LOADING...") << refresh;

    event ev;
    gin.timer(1000/60); //I've poured sacred oils into the gears of my laptop to appease the mighty Machine Spirit. Hopefully this will ensure that 60 FPS is kept

    MainMenu m(ev);
}
