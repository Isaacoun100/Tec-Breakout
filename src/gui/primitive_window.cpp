//
// Created by carlo on 16/9/21.
//
#include "primitive_window.h"

PrimitiveWindow::PrimitiveWindow() {
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(dimensions[0], dimensions[1],
                                0, &window, &renderer);


    char *tmp [title.size() +1];
    strcpy(reinterpret_cast<char *>(tmp), title.c_str());
    SDL_SetWindowTitle(window, reinterpret_cast<const char *>(tmp));
    backgroundColor(0, 255, 255, 255);
    loop();
}

PrimitiveWindow::PrimitiveWindow(string title, int dimensions[]) {
    this->title = std::move(title);
    this->dimensions[0] = dimensions[0];
    this->dimensions[1] =  dimensions[1];
    PrimitiveWindow();
}

PrimitiveWindow::PrimitiveWindow(string title, int dimensions[], bool running) {
    this->running = running;
    PrimitiveWindow(title, dimensions);
}

PrimitiveWindow::~PrimitiveWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void PrimitiveWindow::loop(){
    while (running){


        lastFrame=SDL_GetTicks();
        static int lastTime;
        if(lastFrame >= (lastTime+1000)) {lastTime=lastFrame; frameCount=0;}


        input();
        update();
        render();

    }
}

void PrimitiveWindow::input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type==SDL_QUIT) { stop(); break;}
        if (event.type==SDL_KEYDOWN){
            if(event.key.keysym.sym==SDLK_UP){cout << "UPING" << endl;}
            if(event.key.keysym.sym==SDLK_DOWN){cout << "DOWNIG" << endl;}
            if(event.key.keysym.sym==SDLK_RIGHT){cout << "RIGHTING" << endl;}
            if(event.key.keysym.sym==SDLK_LEFT){cout << "LEFTING" << endl;}
        }
    }
}

void PrimitiveWindow::render() {


    //Frames counter
    frameCount ++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)) {
        SDL_Delay((1000/60)-timerFPS);
    }


    SDL_RenderPresent(renderer);
}

void PrimitiveWindow::update() {
    SDL_UpdateWindowSurface(window);
}

void PrimitiveWindow::run(){
    this->running = true;
    loop();
}

void PrimitiveWindow::stop() {
    this->running = false;
}

void PrimitiveWindow::backgroundColor(int red, int green, int blue, int transparency){
    SDL_SetRenderDrawColor(renderer, red, green, blue, transparency);
    SDL_RenderClear(renderer);
}
