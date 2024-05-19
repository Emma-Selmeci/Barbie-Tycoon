#ifndef STATICDATA.HPP
#define STATICDATA.HPP

#include "imageLoader.hpp"

struct StaticData {
    static ImageLoader leftArrow, rightArrow;
    static int dollToParts(int);
    static std::string dollToName(int);
};

#endif // STATICDATA
