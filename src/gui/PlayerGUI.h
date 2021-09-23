//
// Created by carlo on 22/9/21.
//

#ifndef TEC_BREAKOUT_PLAYERGUI_H
#define TEC_BREAKOUT_PLAYERGUI_H


#include "primitive_window.h"

class PlayerGUI : public PrimitiveWindow{
public:
    string txtInput = "";
    void input() override;
    PlayerGUI();
    void run() override;
};


#endif //TEC_BREAKOUT_PLAYERGUI_H
