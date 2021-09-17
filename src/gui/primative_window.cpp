//
// Created by carlo on 16/9/21.
//
#include <SDL.h>
#include "primative_window.h"

PrimativeWindow::PrimativeWindow() {
    title = "PrimativeWindow";
    dimensions[0] = dimensions[1] = 500;
    position [0] = position [1] = 300;
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(dimensions[0],
                     dimensions[1],
                     0, &window, &renderer);
    char cstr [title.size() +1];
    strcpy(cstr, title.c_str());
    SDL_SetWindowTitle(window, cstr);
    running = true;
    loop();
}

PrimativeWindow::~PrimativeWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void PrimativeWindow::loop(){
    while (running){
        lastFrame = SDL_GetTicks();
        static int lastTime;
        if (lastFrame >= (lastTime+1000)){
            lastTime = lastFrame;
            frameCount = 0;
        }
         render();
        events();
    }
}

void PrimativeWindow::render() {
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = dimensions[0];
    rect.h = dimensions[1];
    SDL_RenderFillRect(renderer, &rect);
    frameCount ++;
    int  timeFPS = SDL_GetTicks()-lastFrame;
    if(timeFPS<(1000/60)){
        SDL_Delay((1000/60)-timeFPS);
    }
    SDL_RenderPresent(renderer);
}

void PrimativeWindow::events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}

