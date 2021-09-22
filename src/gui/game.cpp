//
// Created by carlo on 18/9/21.
//

#include "game.h"
#include "object_sdl.h"
#include "text_sdl.h"
#include "brick.h"
#include <random>


Game::Game() {
    PrimitiveWindow::initWindow("TecBreakout",
                                1500, 1000);
}

void Game::resetGame(){
    bar = Bar(width/4,14,height-height/16);
    ball = Ball(16);

    bool deepBricks [ROW][COL];
    fill(*deepBricks, *deepBricks + ROW + COL, false);
    srand(time(NULL));
    int randomNum;
    for (int i= ROW-1; 0<=i; i--){
        for (int j = COL-1; 0<=j; j--){
            randomNum = rand() % (1+Surprise - Commun) +Commun;
            auto typeBrick = static_cast<TypeBrick>(randomNum);

            Brick brick =Brick((width-(SPACING*COL))/COL,
                               22, typeBrick);
            brick.setId(idObjects++);
            matrixBrick[i][j] = brick;
        }
    }

    bar.rect.x=(width/2)-(bar.rect.w/2);
    ball.rect.y = bar.rect.y-(bar.rect.h*4);
    velY= ball.speed /2;
    velX=0;
    ball.rect.x=width/2-(ball.size/2);
}

void Game::loop() {

    while(running) {
        lastFrame=SDL_GetTicks();
        static int lastTime;
        if(lastFrame >= (lastTime+1000)) {lastTime=lastFrame; frameCount=0;}
        update();
        input();
        render();
    }
}

void Game::run(){
    PrimitiveWindow::initWindow();
    bar = Bar(width/4,14,height-height/16);
    ball = Ball(16);
    text1 = TextSDL("LIVES "+  std::to_string(liveCount),
                    width / 2 + FONT_SIZE / 2+100, FONT_SIZE * 1.5,
                    0, 0, 0, font1);

    text2 = TextSDL("POINTS "+ std::to_string(points),
                    width / 2 + FONT_SIZE / 2 -100, FONT_SIZE * 1.5,
                    0, 0, 0, font1);

    text1.setId(idObjects++);
    text2.setId(idObjects++);
    bar.setId(idObjects++);
    ball.setId(idObjects++);

    Brick value = Brick();
    fill(*matrixBrick, *matrixBrick + ROW * COL, value);
    resetGame();
    PrimitiveWindow::run();
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    PrimitiveWindow::refresh();

    text1.draw(renderer);
    text2.draw(renderer);
    ball.draw(renderer);
    bar.draw(renderer);

    int x = 0;
    for(int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            Brick *brick  = &matrixBrick[i][j];;
            if (brick->isAlive && 0 < abs(brick->hits)) {
                setBricks(brick, x);
                brick->draw(renderer);
            }
            x++;
        }
    }

    SDL_RenderPresent(renderer);
}

void Game::input() {
    SDL_Event e;
    const Uint8 *keyboardState = SDL_GetKeyboardState(nullptr);
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT) {stop();}
    }

    if(keyboardState[SDL_SCANCODE_LEFT]) {
        moveToLeftBar();
    }

    if(keyboardState[SDL_SCANCODE_RIGHT]){
        moveToRightBar();
    }
}

void Game::update() {
    if(liveCount<=0) {resetGame();}

    if(SDL_HasIntersection(&(ball.rect), &(bar.rect))) {
        double rel=(bar.rect.x+(bar.rect.w/2))-(ball.rect.x+(ball.size/2));
        double norm=rel/(bar.rect.w/2);
        double bounce = norm* (5*PI/12);
        velY=-ball.speed*cos(bounce);
        velX=ball.speed*-sin(bounce);
    }

    if(ball.rect.y<=0) {velY=-velY;}

    if(ball.rect.y+ball.size>=height) {velY=-velY;liveCount--;}

    if(ball.rect.x<=0 || ball.rect.x+ball.size>=width) {velX=-velX;}

    ball.rect.x+=velX;
    ball.rect.y+=velY;



    bool reset = true;
    for(int i=0; i<ROW; i++) {
        for (int j = 0; j < COL; j++) {
            Brick *brick = &matrixBrick[i][j];
            if (SDL_HasIntersection(&(ball.rect),
                                    &(brick->rect))&&brick->isAlive) {
                if (brick->hits-1 == 0){
                    //Logica de para diferenytes bloques
                    brick->hits -= 1;
                    brick->isAlive = false;
                    brick->isFront = false;
                    points += brick->value;
                }
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
            }
            if (brick->isAlive) { reset = false; }
        }
    }
    if(reset) { resetGame();}

    text1.setText("LIVES "+  std::to_string(liveCount));
    text2.setText("POINTS "+ std::to_string(points));
}

void Game::setBricks(Brick *brick, int i) {
    brick->rect.x=(((i%COL)+1)*SPACING)+((i%COL)*brick->rect.w)-(SPACING/2);
    brick->rect.y=brick->rect.h*3+(((i%ROW)+1)*SPACING)+((i%ROW)*brick->rect.h)-(SPACING/2);
}

bool Game::moveToRightBar(){
    bool condition = bar.rect.x -bar.speed > 0;
    if(condition) {
        bar.rect.x += bar.speed;
    }
    return condition;
}
bool Game::moveToLeftBar(){
    bool condition = bar.rect.x+bar.rect.w<width-10;
    if (condition){
        bar.rect.x-=bar.speed;
    }
    return condition;
}

