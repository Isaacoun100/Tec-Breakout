/**
 * @file primitive_window.h
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */


#ifndef TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#define TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

/**
 * @brief The father of the subclass windows GUI.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class PrimitiveWindow{
protected:
    /**
     * The window of the GUI.
     */
    SDL_Window *window{};

    /**
     * The render of the window.
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

    /**
     * Count the time of the frames.
     */
    int timerFPS{};

    /**
     *@brief Is loop of the window.
     */
    void loop();

    /**
     * @brief The input keys for the window.
     */
    void input();

    /**
     * @brief Updates the objects and the window.
     */
    void update();

    /**
     * @brief Render the window and the objects in the window.
     */
    void render();

public:
    /**
     * The run var of the loop.
     */
    bool running = false;

    /*
     * The dimensions of the window.
     */
    int dimensions[2]={500, 500};

    /*
     * The title of the window.
     */
    string title = "PrimitiveWindow";

    /**
     * @brief The default constructor.
     */
    PrimitiveWindow();

    /**
     * @brief The constructor change with change tittle and dimensions.
     * @param title Assign the title of the window.
     * @param dimensions Assign the dimensions of the window.
     */
    PrimitiveWindow(string title, int dimensions[]);

    /**
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

    /**
     * @brief The dimensions of the window.
     * @return The dimensions of the window.
     */
    const int *getDimensions() const;

    /**
     * @brief The title of the window.
     * @return The title of the window.
     */
    const string &getTitle() const;
};

#endif //TEC_BREAKOUT_PRIMATIVE_WINDOW_H