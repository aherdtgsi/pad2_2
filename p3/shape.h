//
// Created by Andi on 07.12.2021.
//

#ifndef PAD2_2_SHAPE_H
#define PAD2_2_SHAPE_H

#include "vector"
#include "line.h"
#include "frame.h"

class shape {
protected:
    std::vector<line> lines;
public:
    shape();
    void draw(frame* fr);
};


#endif //PAD2_2_SHAPE_H
