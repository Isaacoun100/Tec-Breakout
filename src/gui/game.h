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
/**
 * @brief The Window for the game.
 * @author Carlos A. Mata C. <carlos.andres12001 @ gmail.com>
 */
class Game:public PrimitiveWindow{
private:

    /**
     * The nun PI.
     */
    constexpr static const double PI = 3.14159265358979323846;

    /**
     * The num of the columns  the matrixBrick.
     */
    static const int COL = 7;

    /**
     * THe num of the rows the matrixBricks.
     */
    static const int ROW = 3;

    /**
     * The for bricks.
     */
    static const int SPACING = 10;

    /**
     * The num of the life.
     */
    int liveCount = 5;

    /**
     * The nums of the player.
     */
    int points = 0;

    /**
     * The id fot the Objects.
     */
    int idObjects = -1000;

    /**
     * The velocity in direction in y.
     */
    float velY = 0;

    /**
    * The velocity in direction in y.
     */
    float velX = 0;

    /**
     * um for prevent a bug in the ball.
     */
    int antiBugs;

    /**
     * The counter of the seconds.
     */
    int counterSeconds;

    /**
     * This tribute is used in event surprise.
     */
    bool recoverEvent = false;

    /**
     * The bar entity.
     */
    Bar bar;

    /**
     * The ball entity.
     */
    Ball ball;

    /**
     * The matrix storage the bricks game.
     */
    Brick matrixBrick[ROW][COL];

    /**
     * The display for the text live..
     */
    TextSDL text1;

    /**
     * The display for the text points.
     */
    TextSDL text2;

    /**
     * The display fot the ball features.
     */
    TextSDL text3;

    /**
     * The display fir the bar features.
     */
    TextSDL text4;

    /**
     * THe display for the last surprise.
     */
    TextSDL text5;

    /**
    * @brief Set the features of the game so that game init.  .
    */
    void resetGame();

    /**
     * @brief Override the method loop.
     */
    void loop() override;

    /**
     * @brief Override the method renderer.
     */
    void render() override;

    /**
    * @brief Override the method inout.
    */
    void input() override;

    /**
    * @brief Override the method update.
    */
    void update() override;

    /**
     * @brief DO the surprise event..
     */
    void surpriseEvent(int *num);

    /**
    * @brief Swap the bricks.
    */
    void swapBricks(Brick *a, Brick *b);

public:

    /**
    * @brief THe constructor of the class put the tittle and dimensions.
    */
    Game();

    /**
    * @brief Override the method run.
    */
    void run() override ;

    /**
    * @brief Move the bar to the right..
    */
    bool moveToRightBar();

    /**
    * @brief Move the bar to the left.
    */
    bool moveToLeftBar();

};


#endif //TECBREAKOUT_GAME_H
