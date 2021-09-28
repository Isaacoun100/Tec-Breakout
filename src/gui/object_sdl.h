//
// Created by carlo on 18/9/21.
//

#ifndef TECBREAKOUT_OBJECT_SDL_H
#define TECBREAKOUT_OBJECT_SDL_H
#include "SDL2/SDL.h"
/**
 * @brief The interface to create a object in SDL2.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class ObjectSDL{
private:

    /**
     * The id of the object.
     */
    int id;

public:

    /**
    * @brief This method draw fot the object.
     * @param The renderer of the window.
     */
    virtual void draw(SDL_Renderer *renderer) = 0;

    /**
     * @brief Return the id tribute.
     * @return Return the id tribute.
     */
    virtual int getId() {return id;}

    /**
     * @brief Set the id tribute.
     * @param id Set the id tribute.
     */
    virtual void setId(int id) {this->id = id;}
};


#endif //TECBREAKOUT_OBJECT_SDL_H
