//
// Created by carlo on 18/9/21.
//

#ifndef TECBREAKOUT_OBJECT_SDL_H
#define TECBREAKOUT_OBJECT_SDL_H
#include "SDL2/SDL.h"

class ObjectSDL{
private:
    int id;
public:
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual int getId() {return id;}

    virtual void setId(int id) {this->id = id;}
};


#endif //TECBREAKOUT_OBJECT_SDL_H
