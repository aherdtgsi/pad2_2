//
// Created by Andi on 03.12.2021.
//

#ifndef PAD2_2_LINE_H
#define PAD2_2_LINE_H
#include "frame.h"
#include "point.h"
#include "iostream"
using std::cout;
using std::endl;


class line {
private:
    point p1, p2;

public:
    line();
    line(point p1, point p2);
    line(unsigned int x1,unsigned int y1 ,unsigned int x2,unsigned int y2);
    void set_line(unsigned int x1,unsigned int y1 ,unsigned int x2,unsigned int y2);
    void draw(frame* fr);
};


#endif //PAD2_2_LINE_H
