#include "colors.hpp"

#include "gameManager.hpp"

Color transformColor(Color c1, bool black) {
    float deltaR, deltaG, deltaB;
    Color c2;
    if(!black) c2 = {220,20,60}; else c2 = {0,0,0};
    deltaR = (c1.r-c2.r)/20.0;
    deltaG = (c1.g-c2.g)/20.0;
    deltaB = (c1.b-c2.b)/20.0;
    int corruption = GameManager::transformationCoefficient;
    if(corruption > 20) corruption = 20;
    return{c1.r-deltaR*corruption,c1.g-deltaG*corruption,c1.b-deltaB*corruption};
}
