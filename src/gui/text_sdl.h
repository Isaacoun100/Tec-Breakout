//
// Created by carlo on 18/9/21.
//

#ifndef TECBREAKOUT_TEXT_SDL_H
#define TECBREAKOUT_TEXT_SDL_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include "objectSDL.h"
using namespace std;
#define FONT_SIZE 32

class TextSDL:public ObjectSDL{
public:
    string text;
    SDL_Rect rect;
    int x;
    int y;
    SDL_Color color;

    TextSDL(const TTF_Font &font);

    TextSDL(const string &text, int x, int y, int red, int green, int blue, TTF_Font *font);

    const string &getText() const;

    void setText(const string &text);

    TTF_Font *font;

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    void setColor(int red, int green, int blue);

    void draw(SDL_Renderer *renderer) override;

};

#endif //TECBREAKOUT_TEXT_SDL_H
