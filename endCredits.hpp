#ifndef ENDCREDITS.HPP
#define ENDCREDITS.HPP

#include <vector>

#include "graphics.hpp"

#include "helpers.hpp"
#include "graphicsHelper.hpp"

using namespace genv;

struct EndCredits {
    static std::vector<Color> endImage;
    static Vec2 size;
    static void start(event& ev);
    static void loadImage();
    static Color getPixel(int, int);
};

#endif // ENDCREDITS
