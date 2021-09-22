/**
 * @file primitive_window.h
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */


#ifndef TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#define TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#include "SDL2/SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#define FONT_SIZE 24
using namespace std;

/**
 * @brief The Primitive Window for the program.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class PrimitiveWindow{
protected:
    /**
     * The window of the GUI.
     */
    SDL_Window *window{};

    /**
     * The renderf of the window.
     */
    SDL_Renderer *renderer{};

    /**
     * Count the numbers of frames.
     */
    int frameCount{};

    /**
     * The last frame that was counted.
     */
    int lastFrame{};

    TTF_Font *font1;

    /**
     * Count the time of the frames.
     */
    int timerFPS{};

    virtual /**
     *@brief Is loop of the window.
     */
    void loop();

    virtual /**
     * @brief The input keys for the window.
     */
    void input();

    /**
     * @brief Updates the objects and the window.
     */
    virtual void update();

    virtual /**
     * @brief Render the window and the objects in the window.
     */
    void render();

    /**
    * @brief Manage frames task refresh.
     */
    void refresh();

public:
    /**
     * The run var of the loop.
     */
    bool running = false;

    /**
     * The width of the window.
     */
    int width =500;

    /**
     * The height of the window.
     */
    int height=500;

    /*
     * The title of the window.
     */
    string title = "PrimitiveWindow";

    /**
     * @brief The default constructor.
     */
    void initWindow();

    /**
     * @brief The constructor change with change tittle and dimensions.
     * @param title Assign the title of the window.
     * @param dimensions Assign the dimensions of the window.
     */
    void initWindow(string title, int width, int height);

    virtual /**
     * @brief Runs the window.
     */
    void run();

    /**
     * @brief Stop run the window.
     */
    void stop();

    /**
     * @brief Set the backgroundColor.
     * @param red RGB color red.
     * @param green RBG color green.
     * @param blue RGB color blue.
     * @param transparency RGB transparency.
     */
    void setBackgroundColor(int red, int green, int blue, int transparency);

    /**
     * @brief The destroy method.
     */
    ~PrimitiveWindow();

};

#endif //TEC_BREAKOUT_PRIMATIVE_WINDOW_H