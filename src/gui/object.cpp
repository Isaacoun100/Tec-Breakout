//
// Created by carlo on 16/9/21.
//

#include <SDL_image.h>
#include "object.h"

#include "object.h"

void Object::setDest(int x, int y, int w, int h) {
    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;
}
void Object::setSource(int x, int y, int w, int h) {
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
}
void Object::setImage(string filename, SDL_Renderer *ren) {
    SDL_Surface* surf = IMG_Load(filename.c_str());
    tex = SDL_CreateTextureFromSurface(ren, surf);
}
void Object::draw(Object o, SDL_Renderer *ren) {
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, nullptr, SDL_FLIP_NONE);
}