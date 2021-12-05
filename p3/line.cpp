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
        cout << "is on frame";
    }
    else{
        throw std::out_of_range("out of range");
    }
}
