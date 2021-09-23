//
// Created by carlo on 18/9/21.
//

#include "text_sdl.h"

const string& TextSDL::getText() const {
    return text;
}

void TextSDL::setText(const string &text) {
    this->text = text;
}

int TextSDL::getX() const {
    return x;
}

void TextSDL::setX(int x) {
    this->x = x;
}

int TextSDL::getY() const {
    return y;
}

void TextSDL::setY(int y) {
    this->y = y;
}

void TextSDL::setColor(int red, int green, int blue) {
    this->color.r = red;
    this->color.g = green;
    this->color.b = blue;
    this->color.a = 255;
}

void TextSDL::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer,
                           0,
                           0,
                           0,
                           255);
    SDL_Surface *surface;
    SDL_Texture *texture;
    const char* t=text.c_str();
    surface = TTF_RenderText_Solid(font, t, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect.w=surface->w;
    rect.h=surface->h;
    rect.x=x-rect.w;
    rect.y=y-rect.h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}

TextSDL::TextSDL(const string &text, int x, int y, int red, int green, int blue, TTF_Font *font) : text(text), x(x), y(y),font(font) { setColor(red, green, blue);}

TextSDL::TextSDL() {

}
