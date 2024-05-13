#ifndef IMAGELOADER.HPP
#define IMAGELOADER.HPP

#include "graphics.hpp"

#include "helpers.hpp"

using namespace genv;

//A very simple .kep loader class

class ImageLoader {
private:
    Vec2 pos;
    Vec2 size;
    canvas c;
    void loadImage();
public:
    ImageLoader(std::string path);
    ImageLoader(std::string path, Vec2 pos);
    void setPos(Vec2 newPos);
    void draw();
    void draw(Vec2 newPos);
    void setTransparent(bool);
};

#endif // IMAGELOADER
