#include "colors.hpp"

#include "gameManager.hpp"

Color transformColor(Color c) {
    float deltaR, deltaG, deltaB;
    deltaR = c.r/20.0;
    deltaG = c.g/20.0;
    deltaB = c.b/20.0;
    int corruption = GameManager::transformationCoefficient;
    if(corruption > 20) corruption = 20;
    return{c.r-deltaR*corruption,c.g-deltaG*corruption,c.b-deltaB*corruption};
}
