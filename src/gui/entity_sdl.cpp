//
// Created by carlo on 20/9/21.
//


#include "entity_sdl.h"

/**
* @brief This method draw fot the object.
 * @param The renderer of the window.
 */
void EntitySDL::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer,
                           color.red,
                           color.green,
                           color.blue,
                           color.t);
    SDL_RenderFillRect(renderer, &rect);
}
