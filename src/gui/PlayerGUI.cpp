//
// Created by carlo on 22/9/21.
//

#include "PlayerGUI.h"

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

PlayerGUI::PlayerGUI() {
    PrimitiveWindow::initWindow("Player Window", 200, 200);
}

void PlayerGUI::run() {
    PrimitiveWindow::initWindow();
    this->running = true;
    this->loop();
}
