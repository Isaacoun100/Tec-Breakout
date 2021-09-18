/**
 * @file object.cpp
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
#include <SDL_image.h>
#include "object.h"

#include "object.h"

/**
 * @brief Set the location.
 * @param x Set in x1.
 * @param y Set in y1.
 * @param w Set in x2.
 * @param h Set in y2.
 */
void Object::setDest(int x, int y, int w, int h) {
    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;
}

/**
 * @brief Set the surface.
 * @param x Set in x1.
 * @param y Set in y1.
 * @param w Set in x2.
 * @param h Set in y2.
 */
void Object::setSource(int x, int y, int w, int h) {
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
}

/**
 * Return the texture.
 * @return Return the texture.
 */
void Object::setImage(string filename, SDL_Renderer *renderer) {
    SDL_Surface* surf = IMG_Load(filename.c_str());
    tex = SDL_CreateTextureFromSurface(renderer, surf);
}

/**
 * Draw the object.
 * @param o THe object to draw.
 * @param renderer The render of the window.
 */
void Object::draw(Object o, SDL_Renderer *renderer) {
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(renderer, o.getTex(), &src, &dest, 0, nullptr, SDL_FLIP_NONE);
}