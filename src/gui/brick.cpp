//
// Created by carlo on 20/9/21.
//

#include "brick.h"

Brick::Brick(int w, int h, typeBrick type) {
    this->rect.w = w;
    this->rect.h = h;
    this->type = type;
    setFeatureBrick();
}

void Brick::setFeatureBrick(){
    if (type==Commun){
        value = 10;
        hits = 1;
        color.red = 255;
    }
    if(type==Double){
        value = 15;
        hits = 2;
        color.red = 58;
        color.green = 190;
        color.blue = 242;
    }
    if (type==Triple){
        value = 20;
        hits = 3;
        color.red = 58;
        color.green = 242;
        color.blue = 119;
    }
    if (type==Deep){
        value = 0;
        hits = -1;
        color.red = 227;
        color.green = 91;
        color.blue = 195;
    }
    if (type==Inside){
        value = 30;
        hits = 1;
        color.red = 220;
        color.green = 237;
        color.blue = 36;
    }
    if (type==Surprise){
        value = 0;
        hits = 1;
        color.red = 150;
        color.green = 81;
        color.blue = 196;
    }
}

Brick::Brick() {
}
