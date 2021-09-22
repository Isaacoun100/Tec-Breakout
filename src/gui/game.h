//
// Created by carlo on 18/9/21.
//

#ifndef TECBREAKOUT_GAME_H
#define TECBREAKOUT_GAME_H


#include "primitive_window.h"
#include "bar.h"
#include "brick.h"
#include "ball.h"
#include "text_sdl.h"

class Game:public PrimitiveWindow{
public:

    constexpr static const double PI = 3.14159265358979323846;
    static const int COL = 7;
    static const int ROW = 5;
    static const int SPACING = 10;

    int liveCount = 3;

    int points = 0;

    int idObjects = -1000;

    float velY = 0;

    float velX = 0;

    Bar bar;

    Ball ball;

    Brick matrixBrick[ROW][COL];

    TextSDL text1;

    TextSDL text2;



    Game();

    void loop() override;

    void resetGame();

    void render() override;

    void input() override;

    void update() override;

    void setBricks(Brick *brick,int i);

    bool moveToRightBar();

    bool moveToLeftBar();

    void run();
};


#endif //TECBREAKOUT_GAME_H
