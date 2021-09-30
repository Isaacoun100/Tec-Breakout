//
// Created by carlo on 18/9/21.
//

#include "game.h"
#include "object_sdl.h"
#include "text_sdl.h"
#include "brick.h"
#include <random>

/**
* @brief THe constructor of the class put the tittle and dimensions.
*/
Game::Game() {
    PrimitiveWindow::initWindow("TecBreakout",
                                1500, 1000);
}

/**
* @brief Set the features of the game so that game init.  .
*/
void Game::resetGame(){
    bar = Bar(width/4,14,height-height/16);
    ball = Ball(16);

    bool deepBricks [ROW][COL];
    for (int i= 0; i<ROW; i++) {
        for (int j = 0; j < COL; j++) {
            deepBricks[i][j] = false;
        }
    }



    srand(time(NULL));
    int randomNum;
    for (int i= ROW-1; 0<=i; i--){
        for (int j = COL-1; 0<=j; j--){
            randomNum = rand() % (1+Deep - Commun) +Commun;

            for (int x = ROW-1; 1<=x; x--){
                if(deepBricks[x][j]&&i<x){
                    randomNum = Inside;
                    break;
                }
            }

            if ( randomNum==Deep){
                if(i==1){
                    deepBricks[i][j] = true;
                }
                else{
                    randomNum = rand() % (1+Surprise - Commun) + Commun;
                }
            }


            auto typeBrick = static_cast<TypeBrick>(randomNum);

            Brick brick =Brick((width-(SPACING*COL))/COL,
                               22, typeBrick);
            brick.setId(idObjects++);
            if(i==ROW-1){
                brick.isFront = true;
            }
            matrixBrick[i][j] = brick;
        }
    }

    bar.rect.x=(width/2)-(bar.rect.w/2);
    ball.rect.y = bar.rect.y-(bar.rect.h*4);
    velY= ball.speed /2;
    velX=0;
    ball.rect.x=width/2-(ball.size/2);
}

/**
 * @brief Override the method loop.
 */
void Game::loop() {

    while(running) {
        lastFrame=SDL_GetTicks();
        static int lastTime;
        if(lastFrame >= (lastTime+1000)) {lastTime=lastFrame; frameCount=0; counterSeconds++;}
        update();
        input();
        render();
    }
}

/**
* @brief Override the method run.
*/
void Game::run(){
    PrimitiveWindow::initWindow();
    bar = Bar(width/4,14,height-height/16);
    ball = Ball(16);
    text1 = TextSDL("LIVES "+  std::to_string(liveCount),
                    width / 2 + FONT_SIZE / 2+150, FONT_SIZE * 1.5,
                    0, 0, 0, font1);

    text2 = TextSDL("POINTS "+ std::to_string(points),
                    width / 2 + FONT_SIZE / 2+25, FONT_SIZE * 1.5,
                    0, 0, 0, font1);

    text3 =TextSDL("Ball (Speed: "+ std::to_string(ball.speed) + " Deep: "+ std::to_string(ball.deep) +")",
                   width / 2 + FONT_SIZE / 2 -150, FONT_SIZE * 1.5,
                   0, 0, 0, font1);

    text4 = TextSDL("Bar (Speed: "+ std::to_string(bar.speed) + " Width: "+ std::to_string(bar.rect.w)+")" ,
                    width / 2 + FONT_SIZE / 2 +600, FONT_SIZE * 1.5,
                    0, 0, 0, font1);

    text5 = TextSDL("Last surprise was ",
                    width / 2 + FONT_SIZE / 2 -425, FONT_SIZE * 1.5,
                    0, 197, 172, font1);

    text1.setId(idObjects++);
    text2.setId(idObjects++);
    text3.setId(idObjects++);
    text4.setId(idObjects++);
    text5.setId(idObjects++);

    bar.setId(idObjects++);
    ball.setId(idObjects++);

    Brick value = Brick();
    fill(*matrixBrick, *matrixBrick + ROW * COL, value);
    resetGame();
    this->running = true;
    this->loop();
}

/**
 * @brief Override the method renderer.
 */
void Game::render(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    PrimitiveWindow::refresh();

    text1.draw(renderer);
    text2.draw(renderer);
    text3.draw(renderer);
    text4.draw(renderer);
    text5.draw(renderer);

    ball.draw(renderer);
    bar.draw(renderer);

    for(int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            Brick *brick  = &matrixBrick[i][j];;
            if (brick->isAlive && 0 < abs(brick->hits)) {
                brick->rect.x = ((j+1)*SPACING)+(j*brick->rect.w)-(SPACING/2);
                brick->rect.y = brick->rect.h*3+((i+1)*SPACING)+(i*brick->rect.h)-(SPACING/2);
                brick->draw(renderer);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

/**
* @brief Override the method inout.
*/
void Game::input() {
    SDL_Event e;
    const Uint8 *keyboardState = SDL_GetKeyboardState(nullptr);
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT) {
            exit(0);
        }
    }
}

/**
* @brief Override the method update.
*/
void Game::update() {
    if(liveCount<=0) {stop();}

    if(SDL_HasIntersection(&(ball.rect), &(bar.rect))) {
        double rel=(bar.rect.x+(bar.rect.w/2))-(ball.rect.x+(ball.size/2));
        double norm=rel/(bar.rect.w/2);
        double bounce = norm* (5*PI/12);
        velY=-ball.speed*cos(bounce);
        velX=ball.speed*-sin(bounce);
    }
    int i =0, j =0;
    Brick *brick  = &matrixBrick[i][j];;
    if(ball.rect.y<=brick->rect.h*3+((i+1)*SPACING)+(i*brick->rect.h)-(SPACING/2)) {
        velY=-velY;
        antiBugs ++;
        if (antiBugs> 20){
            ball.rect.y = height-height/2;
            antiBugs = 0;
        }
    }else{
        antiBugs = 0;
    }

    int num =0;
    if(ball.rect.y+ball.size>=height) {
        velY=-velY;
        liveCount--;
        surpriseEvent(&num);
    }
    int randomArray[2] = {0, 3};
    num = randomArray[rand() % (1+1 - 0) +0];

    if(counterSeconds % 120 == 0 && counterSeconds != 0 ) {
        if (!recoverEvent) {
            surpriseEvent(&num);
            recoverEvent = true;
        }
    }else {
        recoverEvent = false;
    }

    if(ball.rect.x<=0 || ball.rect.x+ball.size>=width) {velX=-velX;}

    ball.rect.x+=velX;
    ball.rect.y+=velY;



    bool reset = true;
    for(int i=0; i<ROW; i++) {
        for (int j = 0; j < COL; j++) {
            Brick *brick = &matrixBrick[i][j];
            if (SDL_HasIntersection(&(ball.rect),
                                    &(brick->rect))&&brick->isAlive) {

                if (ball.rect.x >= brick->rect.x) {
                    velX = -velX;
                    ball.rect.x -= 20;
                }
                if (ball.rect.x <= brick->rect.x) {
                    velX = -velX;
                    ball.rect.x += 20;
                }
                if (ball.rect.y <= brick->rect.y) {
                    velY = -velY;
                    ball.rect.y -= 20;
                }
                if (ball.rect.y >= brick->rect.y) {
                    velY = -velY;
                    ball.rect.y += 20;
                }

                if (brick->type==Commun){
                    brick->hits -= 1;
                    if(brick->hits<=0){
                        brick->isAlive = false;
                        brick->isFront = false;
                        points += brick->value;
                    }
                }

                else if(brick->type==Double){
                    brick->hits -= 1;
                    if(brick->hits<=0){
                        brick->isAlive = false;
                        brick->isFront = false;
                        points += brick->value;
                    }
                }
                else if(brick->type==Triple){
                    brick->hits -= 1;
                    if(brick->hits==0){
                        brick->isAlive = false;
                        brick->isFront = false;
                        points += brick->value;
                    }
                }
                else if(brick->type==Surprise){
                    brick->hits -= 1;
                    if(brick->hits==0){
                        brick->isAlive = false;
                        brick->isFront = false;
                        points += brick->value;
                    }
                    int num = rand() % (1+4 - 0) +0;
                    surpriseEvent(&num);
                }
                else if(brick->type==Deep){
                    if(i!=0){
                        if(ball.deep%i!=0 && i!=1){
                            Brick *b2 = &(matrixBrick[i-1][j]);
                            b2->isAlive = false;
                            swapBricks(brick,b2);
                            render();
                        }
                        else if(i==1 && ball.deep>0){
                            (matrixBrick[0][j]).isAlive = false;
                            brick->isAlive = false;
                        }
                    }
                    ball.deep += 1;
                }
            }
            if (brick->isAlive) { reset = false; }
        }
    }
    if(reset) { resetGame();}

    text1.setText("LIVES "+  std::to_string(liveCount));
    text2.setText("POINTS "+ std::to_string(points));
    text3.setText("Ball (Speed: "+ std::to_string(ball.speed) + " Deep: "+ std::to_string(ball.deep) +")");
    text4.setText("Bar (Speed: "+ std::to_string(bar.speed) + " Width: "+ std::to_string(bar.rect.w)+")");
}

/**
 * @brief DO the surprise event..
 */
void Game::surpriseEvent(int *num){
    string txt = "";
    switch (*num) {
        case 0:
            bar.rect.w -= bar.rect.w/16;
            txt = "-width Bar ";
            if(bar.rect.w<=100){
                bar.rect.w += 200;
                txt = "+width Bar ";
            }
            break;
        case 1:
            bar.rect.w += bar.rect.w/2;
            txt = "+width Bar ";
            if(bar.rect.w>=width-100){
                bar.rect.w -= bar.rect.w/2;
                txt = "-width Bar ";
            }
            break;
        case 2:
            ball.speed += 2;
            txt = "+speed Ball ";
            if(ball.speed>=20){
                ball.speed -= 4;
                txt = "-speed Ball ";
            }
            break;
        case 3:
            ball.speed -= 1;
            txt = "-speed Ball ";
            if(ball.speed<=2){
                ball.speed = 4;
                txt = "+speed Ball ";
            }
            break;
        case 4:
            ball.speed = 8;
            bar.rect.w = width/4;
            txt = "Restore    ";
    }
    text5.setText("Last surprise was " + txt);
}

/**
    * @brief Swap the bricks.
    */
void Game::swapBricks( Brick *a, Brick* b){
    Brick temp = *b;
    *a=*b;
    *b = temp;
}

/**
* @brief Move the bar to the right..
*/
bool Game::moveToRightBar(){
    bool condition = bar.rect.x+bar.rect.w+bar.speed<width-10;

    if(condition) {
        bar.rect.x += bar.speed;
    }
    return condition;
}

/**
* @brief Move the bar to the left.
*/
bool Game::moveToLeftBar(){
    bool condition = bar.rect.x -bar.speed > 10;
    if (condition){
        bar.rect.x-=bar.speed;
    }
    return condition;
}

