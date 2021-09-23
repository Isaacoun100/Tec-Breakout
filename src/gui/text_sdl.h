//
// Created by carlo on 18/9/21.
//

#ifndef TECBREAKOUT_TEXT_SDL_H
#define TECBREAKOUT_TEXT_SDL_H

#include "object_sdl.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "string"

using namespace std;

/**
 * @brief The way to create text in SDL2 with classes.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class TextSDL:public ObjectSDL{
public:

    /**
     * The data of the text.
     */
    string text;

    /**
* The size of the object.
*/
    SDL_Rect rect;

    /**
* The position in x in the window.
*/
    int x;

    /**
     * The position in y in the window.
     */
    int y;

    /**
     * The color of the text.
     */
    SDL_Color color;

    /**
     * THe font of the text.
     */
    TTF_Font *font;

    /**
* @brief The default constructor of the class.
    */
    TextSDL();

    /**
     * @brief The constructor if the class width the type of font.
     * @param font The font of the text.
     */
    TextSDL(const TTF_Font &font);

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
    TextSDL(const string &text, int x, int y, int red, int green, int blue, TTF_Font *font);

    /**
     * @brief Set the text of the object.
     * @param text Set the text of the object.
     */
    void setText(const string &text);

    /**
     * @brief Set the color of the text.
     * @param red The red RGB.
     * @param green The green RBG.
     * @param blue The blue RGB.
     */
    void setColor(int red, int green, int blue);

    /**
    * @brief This method draw fot the object.
     * @param The renderer of the window.
     */
    void draw(SDL_Renderer *renderer) override;

};

#endif //TECBREAKOUT_TEXT_SDL_H
