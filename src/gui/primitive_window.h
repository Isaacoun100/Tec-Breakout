//
// Created by carlo on 16/9/21.
//

#ifndef TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#define TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class PrimitiveWindow{
protected:
    SDL_Window *window{};
    SDL_Renderer *renderer{};

    int frameCount{};
    int lastFrame{};
    int timerFPS{};

    void loop();
    void input();
    void update();
    void render();
public:
    bool running = false;
    int dimensions[2]{500, 500};
    string title = "PrimitiveWindow";
    
    PrimitiveWindow();
    PrimitiveWindow(string title, int dimensions[]);
    PrimitiveWindow(string title, int dimensions[], bool running);
    void run();
    void stop();
    void backgroundColor(int red, int green, int blue, int transparency);
    char *getTitleChar() const;
    ~PrimitiveWindow();
};

#endif //TEC_BREAKOUT_PRIMATIVE_WINDOW_H