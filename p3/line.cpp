//
// Created by Andi on 03.12.2021.
//

#include "line.h"

line::line() {

}

line::line(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2) {
    this->p1.set_position(x1,y1);
    this->p2.set_position(x2,y2);
}

void line::set_line(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2) {
    this->p1.set_position(x1,y1);
    this->p2.set_position(x2,y2);
}

void line::draw(frame *fr) {
    if(p1.on_frame() && p2.on_frame()) {
        int x1 = p1.getX();
        int y1 = p1.getY();
        int x2 = p2.getX();
        int y2 = p2.getY();
        int dx = x2 - x1;
        int dy = y2 - y1;
        //direction
        int sx = (dx > 0) ? 1 : -1;
        int sy = (dy > 0) ? 1 : -1;
        dx = std::abs(dx);
        dy = std::abs(dy);
        int err = dx - dy;
        while (true) {
            fr->put_point(x1,y1);
            if (x1 == x2 && y1 == y2) break;
            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }
    else{
        throw std::out_of_range("out of range");
    }
}

line::line(point p1, point p2) {
    this-> p1 = p1;
    this-> p2 = p2;
}

