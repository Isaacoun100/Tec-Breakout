//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_BRICK_H
#define TECBREAKOUT_BRICK_H

#include "entity_sdl.h"
//#include "include_sdl.h"

/**
 * @brief The types of the Bricks.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
enum TypeBrick{
    Commun =0,
    Double=1,
    Triple=2,
    Surprise=3,
    Deep=4,
    Inside=5,
};

/**
 * @brief The object brick of the game.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class Brick: public EntitySDL{
public:

    /**
     * THe default constructor.
     */
    Brick();

    /**
     * The type of the brick.
     */
    TypeBrick type;

    /**
     * The value of points of the brick.
     */
    int value{};

    /**
     * How many hits the brick support,
     */
    int hits{};

    /**
     * Is the brick is alive.
     */
    int isAlive = true;

    /**
     * Is the brick is the last row of the column,
     */
    int isFront = false;

    /**
     * The constructor with w, h, y param.
     * @param w The width of the object.
     * @param h The height of the object.
     * @param type The type of the brick.
     */
    Brick(int w, int h, TypeBrick type);


private:

    /**
     * Set the Feature of the type brick.
     */
    void setFeatureBrick();
};


#endif //TECBREAKOUT_BRICK_H
