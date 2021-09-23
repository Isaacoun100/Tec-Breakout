//
// Created by carlo on 18/9/21.
//

#include "text_sdl.h"

/**
 * @brief Set the text of the object.
 * @param text Set the text of the object.
 */
void TextSDL::setText(const string &text) {
    this->text = text;
}

/**
 * @brief Set the color of the text.
 * @param red The red RGB.
 * @param green The green RBG.
 * @param blue The blue RGB.
 */
void TextSDL::setColor(int red, int green, int blue) {
    this->color.r = red;
    this->color.g = green;
    this->color.b = blue;
    this->color.a = 255;
}

/**
* @brief This method draw fot the object.
 * @param The renderer of the window.
 */
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

/**
 * @brief The constructor of the class.
 * @param text The text of the object.
 * @param x The position x in the window.
 * @param y The position y in the window.
 * @param red The red RGB.
 * @param green The green RBG.
 * @param blue The blue RGB.
 * @param font The font of the text.
 */
TextSDL::TextSDL(const string &text, int x, int y, int red, int green, int blue, TTF_Font *font) : text(text), x(x), y(y),font(font) { setColor(red, green, blue);}

/**
* @brief The default constructor of the class.
*/
TextSDL::TextSDL() {

}
