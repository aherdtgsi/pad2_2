//
// Created by Andi on 03.12.2021.
//

#include "point.h"

point::point() {
    x = 0;
    y = 0;
}

point::point(unsigned int x,unsigned int y) {
    this->x = x;
    this->y = y;
}

void point::set_position(unsigned int x,unsigned int y) {
    this->x = x;
    this->y = y;
}

bool point::on_frame() {
    return (frame::on_frame(this->x,this->y));
}

unsigned int point::getX() const {
    return x;
}

unsigned int point::getY() const {
    return y;
}
