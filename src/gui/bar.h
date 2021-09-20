//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_BAR_H
#define TECBREAKOUT_BAR_H


#include "entity_sdl.h"

class Bar: public EntitySDL{
public:
    int speed = 9;

    Bar(int w, int h, int y);
};

#endif //TECBREAKOUT_BAR_H
