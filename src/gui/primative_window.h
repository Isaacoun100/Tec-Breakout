//
// Created by carlo on 16/9/21.
//

#ifndef TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#define TEC_BREAKOUT_PRIMATIVE_WINDOW_H
#include <string>
#include "SDL.h"

using namespace std;

class PrimativeWindow{
protected:
    SDL_Renderer* renderer{};
    SDL_Window* window;
    string title;
    int dimensions[2]{};
    int position[2]{};
    bool running = false;
    int frameCount, timeFPS, lastFrame;
public:
    PrimativeWindow();
    ~PrimativeWindow();
    void loop();
//    void input();
//    void update();
    void events();
    void render();
};

#endif //TEC_BREAKOUT_PRIMATIVE_WINDOW_H