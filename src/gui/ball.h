//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_BALL_H
#define TECBREAKOUT_BALL_H
#include "entity_sdl.h"

/**
 * @brief The object ball of the game.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class Ball: public EntitySDL{
public:

    /**
     * THe default constructor.
     */
    Ball();

    /**
     * The deep of the ball.
     */
    int deep = 0;

    /**
     * The speed of the ball.
     */
    int speed = 8;

    /**
     * The of the ball.
     */
    int size = 16;

    /**
     * THe constructor with the set size ball.
     * @param size The of the ball.
     */
    Ball(int size);
};


#endif //TECBREAKOUT_BALL_H
