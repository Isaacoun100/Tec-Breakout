//
// Created by carlo on 18/9/21.
//

#include "game.h"
#include "objectSDL.h"
#include "text_sdl.h"
#include "vector"

//ventana
#define WIDTH 620
#define HEIGHT 720

//bar
#define SPEED 9
//ball
#define BALL_SPEED 8
#define SIZE 16
//blocks
#define SPACING 16



SDL_Rect paddle, ball, brick;
float velY, velX;
bool bricks[ROW*COL];



class EntitySDL: ObjectSDL{
public:
    SDL_Rect rect;
    int width;
    int height;
};

class Ball:EntitySDL{
public:
    int deep = 0;
    int speed;
    int size = 16;
};

enum typeBrick{
    Commun,
    Double,
    Triple,
    Deep,
    Inside,
    Surprise,
};

class Brick:EntitySDL{
public:
    typeBrick type;
    int value;
    int hits;
};

class Bar:EntitySDL{
public:
    int speed;
};

class Game:public PrimitiveWindow{
public:

    int liveCount;
    int points;
    int idObjects = -1000;
    float velY;
    float velX;
    vector<ObjectSDL*> objectsArrays[ROW*COL];
//    Bar bar;
//    Ball ball;
//    Brick array[ROW*COL];



    Game();

    void loop() override;

    void resetBricks();

    void render() override;

    void input() override;

    void update() override;

    void setBricks(int i);
};

Game::Game() :PrimitiveWindow("TecBreakout", 620, 720){



    ObjectSDL *text1 = new TextSDL(std::to_string(points),
                            width / 2 + FONT_SIZE / 2, FONT_SIZE * 1.5,
                                  0, 0, 0, font1);
    text1->setId(idObjects++);
    objectsArrays->push_back(text1);

    TextSDL *text2 = new TextSDL(std::to_string(liveCount),
                            10, 10,
                            0, 0, 0, font1);
    text2.setId(idObjects++);
    objectsArrays->push_back(text2);
    


    paddle.h=12; paddle.w=WIDTH/4;
    paddle.y=HEIGHT-paddle.h-32;

    ball.w=ball.h=SIZE;

    brick.w=(WIDTH-(SPACING*COL))/COL;
    brick.h=22;



    resetBricks();
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

void Game::resetBricks(){
    for(int i=0; i<COL*ROW; i++) bricks[i]=1;
    liveCount=3;

    paddle.x=(width/2)-(paddle.w/2);

    ball.y=paddle.y-(paddle.h*4);
    velY=BALL_SPEED/2;
    velX=0;
    ball.x=WIDTH/2-(SIZE/2);
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    PrimitiveWindow::refresh();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderFillRect(renderer, &paddle);
    SDL_RenderFillRect(renderer, &ball);

    for(int i=0; i<COL*ROW; i++) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        if(i%2==0)SDL_SetRenderDrawColor(renderer, 0,255, 0, 255);
        if(bricks[i]) {
            setBricks(i);
            SDL_RenderFillRect(renderer, &brick);
        }
    }

    SDL_RenderPresent(renderer);
}

void Game::input() {
    SDL_Event e;
    const Uint8 *keyboardState = SDL_GetKeyboardState(nullptr);
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT) {running=false;}
    }

    if(keyboardState[SDL_SCANCODE_LEFT]) {paddle.x-=SPEED;}

    if(keyboardState[SDL_SCANCODE_RIGHT]) {paddle.x+=SPEED;}
}

void Game::update() {
    if(liveCount<=0) resetBricks();
    if(SDL_HasIntersection(&ball, &paddle)) {
        double rel=(paddle.x+(paddle.w/2))-(ball.x+(SIZE/2));
        double norm=rel/(paddle.w/2);

        double bounce = norm* (5*PI/12);
        velY=-BALL_SPEED*cos(bounce);
        velX=BALL_SPEED*-sin(bounce);
    }

    if(ball.y<=0) {velY=-velY;}

    if(ball.y+SIZE>=HEIGHT) {velY=-velY;liveCount--;}

    if(ball.x<=0 || ball.x+SIZE>=WIDTH) {velX=-velX;}

    ball.x+=velX;
    ball.y+=velY;

    if(paddle.x<0) {paddle.x=0;}

    if(paddle.x+paddle.w>WIDTH) {paddle.x=WIDTH-paddle.w;}

    bool reset=1;
    for(int i=0; i<COL*ROW; i++) {
        setBricks(i);
        if(SDL_HasIntersection(&ball, &brick) && bricks[i]) {
            bricks[i]=0;
            if(ball.x >= brick.x) {velX=-velX; ball.x-=20;}
            if(ball.x <= brick.x) {velX=-velX; ball.x+=20;}
            if(ball.y <= brick.y) {velY=-velY; ball.y-=20;}
            if(ball.y >= brick.y) {velY=-velY; ball.y+=20;}
        }
        if(bricks[i]) {reset=0;}
    }
    if(reset) {resetBricks();}
}


void Game::setBricks(int i) {
    brick.x=(((i%COL)+1)*SPACING)+((i%COL)*brick.w)-(SPACING/2);
    brick.y=brick.h*3+(((i%ROW)+1)*SPACING)+((i%ROW)*brick.h)-(SPACING/2);
}


