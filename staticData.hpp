#ifndef STATICDATA.HPP
#define STATICDATA.HPP

#include "imageLoader.hpp"

struct StaticData {
    static ImageLoader leftArrow, rightArrow, upArrow, downArrow;
    static int dollToParts(int);
    static std::string dollToName(int);
    static int dollToPrice(int);
};

#endif // STATICDATA
