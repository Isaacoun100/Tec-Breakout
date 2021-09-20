//
// Created by carlo on 18/9/21.
//

#include "game.h"
#include "object_sdl.h"
#include "text_sdl.h"
#include "brick.h"


Game::Game() {
    PrimitiveWindow::initWindow("TecBreakout",
                                620, 720);
    PrimitiveWindow::initWindow();
    bar = Bar(12,height/4,height-height/4-32);
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
    fill(*matrix_brick, *matrix_brick + ROW*COL, value);
    resetGame();
}

void Game::resetGame(){

    for(int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++){
            //Logica de escoger el brick
            Brick brick =Brick((width-(SPACING*COL))/COL,
                                22, Commun);
            brick.setId(idObjects++);
            matrix_brick[i][j] = brick;
        }
    }

    liveCount=3;
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
            Brick *b  = &matrix_brick[i][j];
            if (b->isAlive && 0<abs(b->hits)) {
                setBricks(b, x);
                b->draw(renderer);
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

    if(keyboardState[SDL_SCANCODE_LEFT]) {bar.rect.x -= bar.speed;}

    if(keyboardState[SDL_SCANCODE_RIGHT]) {bar.rect.x+=bar.speed;}
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

    if(bar.rect.x<0) {ball.rect.x=0;}

    if(bar.rect.x+bar.rect.w>width) {bar.rect.x=width-bar.rect.w;}

    bool reset = false;
    for(int i=0; i<ROW; i++) {
        for (int j = 0; j < COL; j++) {
            Brick *brick = &matrix_brick[i][j];
            if (SDL_HasIntersection(&(ball.rect), &(brick->rect))) {
                if (brick->hits-1 == 0){
                    //Logica de para diferenytes bloques
                    brick->hits -= 1;
                    brick->isAlive = false;
                    brick->isFront = false;
                    points += brick->hits;
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
