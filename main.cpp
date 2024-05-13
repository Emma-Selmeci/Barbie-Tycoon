#include "graphics.hpp"

#include "imageLoader.hpp"
#include "mainMenu.hpp"

using namespace genv;


int main()
{
    gout.open(1000,600);

    gout << move_to(200,200) << text("LOADING...") << refresh;

    event ev;
    gin.timer(1000/60); //I've poured sacred oils into the gears of my laptop to appease the mighty Machine Spirit. Hopefully this will ensure that 60 FPS is kept

    MainMenu m(ev);
}
