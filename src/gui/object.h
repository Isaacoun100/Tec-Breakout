/**
 * @file object.h
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */

#ifndef TEC_BREAKOUT_OBJECT_H
#define TEC_BREAKOUT_OBJECT_H
#include <iostream>
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_test_images.h>

/**
 * @brief Basic object in SDL2.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class Object {
private:
    /**
     * The location in the renderer.
     */
    SDL_Rect dest;

    /**
     * The surface of the image.
     */
    SDL_Rect src;

    /**
     * The texture of the object.
     */
    SDL_Texture* tex;
public:
    /**
     * @brief The default constructor.
     */
    Object() = default;

    /**
     * @brief Return the location.
     * @return Return the location.
     */
    SDL_Rect getDest() const {return dest;}

    /**
     * @brief Return the surface.
     * @return Return the surface.
     */
    SDL_Rect getSource() const {return src;}

    /**
     * @brief Set the location.
     * @param x Set in x1.
     * @param y Set in y1.
     * @param w Set in x2.
     * @param h Set in y2.
     */
    void setDest(int x, int y, int w, int h);

    /**
     * @brief Set the surface.
     * @param x Set in x1.
     * @param y Set in y1.
     * @param w Set in x2.
     * @param h Set in y2.
     */
    void setSource(int x, int y, int w, int h);

    /**
     * @brief Set the image.
     * @param filename Path of the file.
     * @param renderer Render of the window.
     */
    void setImage(string filename, SDL_Renderer* renderer);

    /**
     * Return the texture.
     * @return Return the texture.
     */
    SDL_Texture* getTex() const {return tex;}

    /**
     * Draw the object.
     * @param o THe object to draw.
     * @param renderer The render of the window.
     */
    static void draw(Object o, SDL_Renderer *renderer);
};
#endif //TEC_BREAKOUT_OBJECT_H
