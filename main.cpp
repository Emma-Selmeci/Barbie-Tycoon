#include "graphics.hpp"

#include "imageLoader.hpp"

using namespace genv;


int main()
{
    gout.open(400,400);
    //gout << font("LiberationSans-Regular.ttf",20);

    ImageLoader i("testImage.kep");
    i.draw();
    gout << refresh;

    event ev;
    while(gin >> ev) {
    }
    return 0;
}
