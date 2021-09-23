//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_ENTITY_SDL_H
#define TECBREAKOUT_ENTITY_SDL_H

#include "entity_sdl.h"
#include "object_sdl.h"

class EntitySDL: public ObjectSDL{
public:
    SDL_Rect rect;
    struct Color {
        int red = 0;
        int green = 0;
        int blue = 0;
        int t = 255;
    } color;
    void draw(SDL_Renderer *renderer) override;
};

#endif //TECBREAKOUT_ENTITY_SDL_H
