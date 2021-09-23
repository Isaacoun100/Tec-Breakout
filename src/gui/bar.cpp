//
// Created by carlo on 20/9/21.
//

#include "bar.h"

/**
 * The constructor with w, h, y param.
 * @param w The width of the object.
 * @param h The height of the object.
 * @param y The position y of the object.
 */
Bar::Bar(int w, int h, int y) {
    this->rect.w = w;
    this->rect.h = h;
    this->rect.y= y;
}

/**
 * THe default constructor.
 */
Bar::Bar() {

}
