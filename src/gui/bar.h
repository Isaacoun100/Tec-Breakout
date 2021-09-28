//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_BAR_H
#define TECBREAKOUT_BAR_H


#include "entity_sdl.h"

/**
 * @brief The object bar of the game.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class Bar: public EntitySDL{
public:

    /**
     * THe default constructor.
     */
    Bar();

    /**
     * The speed of the ball.
     */
    int speed = 9;

    /**
     * The constructor with w, h, y param.
     * @param w The width of the object.
     * @param h The height of the object.
     * @param y The position y of the object.
     */
    Bar(int w, int h, int y);
};

#endif //TECBREAKOUT_BAR_H
