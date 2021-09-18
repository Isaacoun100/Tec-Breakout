/**
 * @file primitive_window.cpp
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */

#include "primitive_window.h"

/**
 * @brief The default constructor.
 */
PrimitiveWindow::PrimitiveWindow() {
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(dimensions[0], dimensions[1],
                                0, &window, &renderer);


    char *tmp [title.size() + 1];
    strcpy(reinterpret_cast<char *>(tmp), title.c_str());
    SDL_SetWindowTitle(window, reinterpret_cast<const char *>(tmp));
    setBackgroundColor(0, 255, 255, 255);
    loop();
}

/**
 * @brief The constructor change with change tittle and dimensions.
 * @param title Assign the title of the window.
 * @param dimensions Assign the dimensions of the window.
 */
PrimitiveWindow::PrimitiveWindow(string title, int dimensions[]) {
    this->title = std::move(title);
    this->dimensions[0] = dimensions[0];
    this->dimensions[1] =  dimensions[1];
    PrimitiveWindow();
}

/**
 * @brief The destroy method.
 */
PrimitiveWindow::~PrimitiveWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 *@brief Is loop of the window.
 */
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

/**
 * @brief The input keys for the window.
 */
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

/**
 * @brief Render the window and the objects in the window.
 */
void PrimitiveWindow::render() {


    //Frames counter
    frameCount ++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)) {
        SDL_Delay((1000/60)-timerFPS);
    }


    SDL_RenderPresent(renderer);
}

/**
 * @brief Updates the objects and the window.
 */
void PrimitiveWindow::update() {
    SDL_UpdateWindowSurface(window);
}

/**
 * @brief Runs the window.
 */
void PrimitiveWindow::run(){
    this->running = true;
    loop();
}

/**
 * @brief Stop run the window.
 */
void PrimitiveWindow::stop() {
    this->running = false;
}

/**
 * @brief Set the backgroundColor.
 * @param red RGB color red.
 * @param green RBG color green.
 * @param blue RGB color blue.
 * @param transparency RGB transparency.
 */
void PrimitiveWindow::setBackgroundColor(int red, int green, int blue, int transparency){
    SDL_SetRenderDrawColor(renderer, red, green, blue, transparency);
    SDL_RenderClear(renderer);
}

/**
 * @brief The dimensions of the window.
 * @return The dimensions of the window.
 */
const int *PrimitiveWindow::getDimensions() const {
    return dimensions;
}

/**
 * @brief The title of the window.
 * @return The title of the window.
 */
const string &PrimitiveWindow::getTitle() const {
    return title;
}
