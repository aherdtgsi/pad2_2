//
// Created by Andi on 07.12.2021.
//

#ifndef PAD2_2_TRIANGLE_H
#define PAD2_2_TRIANGLE_H
#include "shape.h"
#include "point.h"
#include "line.h"

class triangle : public shape{
public:
    triangle();
    triangle(point p1, point p2, point p3);
    triangle(point p1, unsigned int len1,unsigned int len2,unsigned int len3);
};


#endif //PAD2_2_TRIANGLE_H
