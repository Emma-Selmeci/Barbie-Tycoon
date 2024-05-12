#include <fstream>
#include <iostream>

#include "imageLoader.hpp"

ImageLoader::ImageLoader(std::string path) : ImageLoader(path,{0,0}){}

ImageLoader::ImageLoader(std::string path, Vec2 pos) : pos(pos) {
    std::fstream fin(path);
    std::string input;

    if(!fin.is_open()) {
        std::cout << "File open is not succesful!";
        exit(1);
    }

    fin >> input;
    size.x = stoi(input);
    fin >> input;
    size.y = stoi(input);

    c.open(size.x,size.y);
    c.transparent(true);

    int r, g, b;
    int x=0, y=0;
    for(int i = 0; i < size.x*size.y; i++) {

        fin >> input;
        r = stoi(input);
        fin >> input;
        g = stoi(input);
        fin >> input;
        b = stoi(input);

        c << color(r,g,b) << move_to(x,y) << dot;
        x++;
            if(x == size.x)
            {
                x = 0;
                y++;
            }
    }
}

void ImageLoader::setPos(Vec2 newPos) {
    pos = newPos;
}

void ImageLoader::draw(Vec2 newPos) {
    setPos(newPos);
    draw();
}

void ImageLoader::draw() {
    gout << stamp(c,pos.x,pos.y);
}
