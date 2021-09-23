/**
 * @file player_gui.cpp
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */


#include "player_gui.h"

/**
 * @brief Override the method innput.
 */
void PlayerGUI::input() {
    SDL_Event e;
    const Uint8 *keyboardState = SDL_GetKeyboardState(nullptr);
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT) {stop();}
    }

    if(keyboardState[SDL_SCANCODE_ESCAPE]){
        txtInput="EXIT";
    }

    if(keyboardState[SDL_SCANCODE_LEFT]) {
        txtInput ="LEFT";
    }

    if(keyboardState[SDL_SCANCODE_RIGHT]){
        txtInput ="RIGHT";
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
