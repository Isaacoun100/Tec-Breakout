//
// Created by carlo on 20/9/21.
//

#include "brick.h"

/**
 * The constructor with w, h, y param.
 * @param w The width of the object.
 * @param h The height of the object.
 * @param y The position y of the object.
 */
Brick::Brick(int w, int h, TypeBrick type) {
    this->rect.w = w;
    this->rect.h = h;
    this->type = type;
    setFeatureBrick();
}

/**
 * Set the Feature of the type brick.
 */
void Brick::setFeatureBrick(){
    if (type==Commun){
        value = 10;
        hits = 1;
        color.red = 255;
    }
    if(type==Double){
        value = 15;
        hits = 2;
        color.blue = 255;
    }
    if (type==Triple){
        value = 20;
        hits = 3;
        color.green = 255;
    }
    if (type==Surprise){
        value = 0;
        hits = 1;
        color.red = 150;
        color.blue = 255;
    }
    if (type==Deep){
        value = 0;
        hits = -1;
        color.red = 255;
        color.green = 255;
    }
    if (type==Inside){
        value = 30;
        hits = -1;
        color.red = 140;
        color.green = 140;
        color.blue = 140;
    }

}

/**
 * THe default constructor.
 */
Brick::Brick() {
}
