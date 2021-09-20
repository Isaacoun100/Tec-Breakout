/**
 * @file primitive_window.cpp
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */

#include "primitive_window.h"

/**
 * @brief The default constructor.
 */
 void PrimitiveWindow::initWindow() {
    if(0<SDL_Init(SDL_INIT_EVERYTHING)){cout << "FAIl INIT"<< endl;}
    SDL_CreateWindowAndRenderer(width, height,
                                0, &window, &renderer);

    TTF_Init();
    font1 = TTF_OpenFont("font/OpenSans-Light.ttf", FONT_SIZE);
    char *tmp [title.size() + 1];
    strcpy(reinterpret_cast<char *>(tmp), title.c_str());
    SDL_SetWindowTitle(window, reinterpret_cast<const char *>(tmp));
}

/**
 * @brief The constructor change with change tittle and dimensions.
 * @param title Assign the title of the window.
 * @param width Assign the dimension of the window.
 * @param height Assign the dimension of the window.
 */
void PrimitiveWindow::initWindow(string title, int width, int height) {
    this->title = std::move(title);
    this->width = width;
    this->height =  height;
}

/**
 * @brief The destroy method.
 */
PrimitiveWindow::~PrimitiveWindow() {
    TTF_CloseFont(font1);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
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
    setBackgroundColor(0, 0, 0, 255);
    SDL_RenderClear(renderer);
    refresh();

    setBackgroundColor(255, 255, 255, 255);

    SDL_RenderClear(renderer);

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
 * @brief Manage frames task refresh.
 */
 void PrimitiveWindow::refresh(){
    //Frames counter
    frameCount ++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)) {
        SDL_Delay((1000/60)-timerFPS);
    }
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
 * @brief The title of the window.
 * @return The title of the window.
 */
const string &PrimitiveWindow::getTitle() const {
    return title;
}
