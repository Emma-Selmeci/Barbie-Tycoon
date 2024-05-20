#include "endCredits.hpp"

#include <fstream>
#include <iostream>

Vec2 EndCredits::size;
std::vector<Color> EndCredits::endImage;

void EndCredits::start(event& ev) {
    loadImage();
    gout.load_font("classic.ttf",25);

    float deltaX = 1000.0;
    float deltaY = 600.0;
    int accum = 0;

    while(gin >> ev) {
        accum++;
        if(accum == 100) break;
        if(ev.type == ev_timer) {
            deltaX+=1.0;
            deltaY+=1.0;
            float epsilonX = size.x/deltaX;
            float epsilonY = size.y/deltaY;

            for(int i = 0; i < deltaX; i++) {
                for(int j = 0; j < deltaY; j++) {
                    Color c = getPixel(i*epsilonX,j*epsilonY);
                    gout << move_to(i,j) << color(c.r,c.g,c.b) << dot;
                }
            }

            gout << color(0,0,0);
            gout << move_to(200,450) << text("Hear, O Israel!") << move_to(200,480) << text("The Lord is our God!") << move_to(200,510) << text("The Lord is One!");

            gout << refresh;
        }
    }

    gout.load_font("classic.ttf",15);

    drawRect({0,0},{999,599},{0,0,0});
    gout << color(255,255,255);

    gout << move_to(20,20) << text("With the true Lord of the world arriving,");
    gout << move_to(20,40) << text("your reign was over. You were cast out into the outer darkness,");
    gout << move_to(20,60) << text("never to return. He destroyed your altars and temples with ");
    gout << move_to(20,80) << text("His Holy Hands and bought peace into the world.");

    gout << move_to(20,200) << text("Click to continue");
    gout << refresh;

    while(gin >> ev) {
        if(ev.type == ev_mouse && ev.button == 1) break;
    }

    drawRect({0,0},{999,599},{0,0,0});
    gout << color(255,255,255);

    gout << move_to(20,20) << text("Well, what can I say, thank you for playing though");
    gout << move_to(20,40) << text("this game! I'm sorry if the game was too sacrilegious,");
    gout << move_to(20,60) << text("that was not my goal. I was heavily inspired");
    gout << move_to(20,80) << text("by one of my favorite writers, H.P. Lovecraft,");
    gout << move_to(20,100) << text("the computer game \"Cultist Simulator\", the video");
    gout << move_to(20,120) << text("\"What's the deal with the Nephilim?\" by Trey the explainer,");
    gout << move_to(20,140) << text("and last but not least,");
    gout << move_to(20,160) << text("my experiences growing up in a fanatically religious family.");
    gout << move_to(20,200) << text("I hope you've enjoyed playing, click to exit");

    gout << refresh;

    while(gin >> ev) {
        if(ev.type == ev_mouse && ev.button == 1) break;
    }

    gout << refresh;
}

void EndCredits::loadImage() {
    std::fstream fin("textures/jesus.kep");
    std::string input;

    if(!fin.is_open()) {
        std::cout << "Opening of endImage not successful!";
        exit(1);
    }

    fin >> input;
    size.x = stoi(input);
    fin >> input;
    size.y = stoi(input);

    int r, g, b;
    for(int i = 0; i < size.x*size.y; i++) {

        fin >> input;
        r = stoi(input);
        fin >> input;
        g = stoi(input);
        fin >> input;
        b = stoi(input);

        endImage.push_back(Color{r,g,b});

    }
}

Color EndCredits::getPixel(int x, int y) {
    return endImage[y*size.x+x];
}
