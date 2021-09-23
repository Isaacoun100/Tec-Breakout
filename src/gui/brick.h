//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_BRICK_H
#define TECBREAKOUT_BRICK_H

#include "entity_sdl.h"
//#include "include_sdl.h"

enum TypeBrick{
    Commun =0,
    Double=1,
    Triple=2,
    Surprise=3,
    Deep=4,
    Inside=5,
};


class Brick: public EntitySDL{
public:
    Brick();

    TypeBrick type;
    int value{};
    int hits{};
    int isAlive = true;
    int isFront = false;

    Brick(int w, int h, TypeBrick type);


private:
    void setFeatureBrick();
};


#endif //TECBREAKOUT_BRICK_H
