//
// Created by carlo on 22/9/21.
//

#ifndef TEC_BREAKOUT_PLAYER_GUI_H
#define TEC_BREAKOUT_PLAYER_GUI_H


#include "primitive_window.h"

/**
 * @brief The Window for the player.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class PlayerGUI : public PrimitiveWindow{
private:
    /**
    * @brief Override the method input.
    */
    void input() override;

public:

    /**
     * The string of the inputs fot keyboard.
     */
    string txtInput = "";

    /**
    * @brief THe constructor of the class put the tittle and dimensions.
    */
    PlayerGUI();

    /**
     * @brief Override the method run.
     */
    void run() override;
};


#endif //TEC_BREAKOUT_PLAYER_GUI_H
