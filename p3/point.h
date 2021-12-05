//
// Created by Andi on 03.12.2021.
//

#ifndef PAD2_2_POINT_H
#define PAD2_2_POINT_H
#include "frame.h"


class point {
private:
    unsigned int x, y;
public:
    point();
    point(unsigned int x,unsigned int y);
    void set_position(unsigned int x,unsigned int y);
    bool on_frame();
};


#endif //PAD2_2_POINT_H
