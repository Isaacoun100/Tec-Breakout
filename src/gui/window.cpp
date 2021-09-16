//
// Created by carlo on 16/9/21.
//
#include <SDL.h>
#include "window.h"

PrimitiveWindow::PrimitiveWindow() {
    title = "PrimitiveWindow";
    dimensions[0] = dimensions[1] = 500;
    position [0] = position [1] = 300;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(dimensions[0],
                     dimensions[1],
                     0, &window, &renderer);
    char cstr [title.size() +1];
    strcpy(cstr, title.c_str());
    SDL_SetWindowTitle(window, cstr);

    loop();
}

PrimitiveWindow::~PrimitiveWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void PrimitiveWindow::loop(){
    while (running){
        lastFrame = SDL_GetTicks();
        static int lastTime = 0;
        if (lastFrame >= (lastTime+1000)){
            lastTime = lastFrame;
            frameCount = 0;
            count ++;
        }
         render();
         input();
         update()
    }
}

