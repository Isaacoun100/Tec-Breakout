/**
 * @file player_gui.cpp
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */


#include "player_gui.h"

/**
 * @brief Override the method input.
 */
void PlayerGUI::input() {
    SDL_Event e;
    const Uint8 *keyboardState = SDL_GetKeyboardState(nullptr);
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT) {exit(0);}
    }

    if(keyboardState[SDLK_e]){
        txtInput="E";
    }

    if(keyboardState[SDL_SCANCODE_LEFT]) {
        txtInput ="L";
    }

    if(keyboardState[SDL_SCANCODE_RIGHT]){
        txtInput ="R";
    }

}

/**
 * @brief THe constructor of the class put the tittle and dimensions.
 */
PlayerGUI::PlayerGUI() {
    PrimitiveWindow::initWindow("Player Window", 200, 200);
}

/**
 * @brief Override the method run.
 */
void PlayerGUI::run() {
    PrimitiveWindow::initWindow();
    this->running = true;
    this->loop();
}
