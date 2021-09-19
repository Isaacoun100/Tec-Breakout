//
// Created by carlo on 18/9/21.
//

#ifndef TECBREAKOUT_OBJECTSDL_H
#define TECBREAKOUT_OBJECTSDL_H

class ObjectSDL{
private:
    int id;
public:
    virtual void draw(SDL_Renderer *renderer) = 0;
    virtual int getId() {return id;}

    virtual void setId(int id) {this->id = id;}
};


#endif //TECBREAKOUT_OBJECTSDL_H
