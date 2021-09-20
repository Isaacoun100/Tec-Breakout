//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_BRICK_H
#define TECBREAKOUT_BRICK_H

#include "entity_sdl.h"
//#include "include_sdl.h"

enum typeBrick{
    Commun,
    Double,
    Triple,
    Deep,
    Inside,
    Surprise,
};


class Brick: public EntitySDL{
public:
    typeBrick type;
    int value{};
    int hits{};
    int isAlive = true;
    int isFront = false;

    Brick(int w, int h, typeBrick type);


private:
    void setFeatureBrick();
};


#endif //TECBREAKOUT_BRICK_H
