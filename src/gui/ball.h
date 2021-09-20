//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_BALL_H
#define TECBREAKOUT_BALL_H
#include "entity_sdl.h"


class Ball: public EntitySDL{
public:

    int deep = 0;

    int speed = 8;

    int size = 16;

    Ball(int size);
};


#endif //TECBREAKOUT_BALL_H
