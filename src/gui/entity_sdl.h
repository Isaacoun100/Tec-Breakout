//
// Created by carlo on 20/9/21.
//

#ifndef TECBREAKOUT_ENTITY_SDL_H
#define TECBREAKOUT_ENTITY_SDL_H

#include "entity_sdl.h"
#include "object_sdl.h"

/**
 * @brief The way to create entities in SDL2 with classes.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class EntitySDL: public ObjectSDL{
public:
    /**
* The size of the object.
*/
    SDL_Rect rect;

    /**
 * The color of the text.
 */
    struct Color {
        int red = 0;
        int green = 0;
        int blue = 0;
        int t = 255;
    } color;

    /**
    * @brief This method draw fot the object.
     * @param The renderer of the window.
     */
    void draw(SDL_Renderer *renderer) override;
};

#endif //TECBREAKOUT_ENTITY_SDL_H
