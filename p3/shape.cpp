//
// Created by Andi on 07.12.2021.
//

#include "shape.h"

shape::shape() = default;

void shape::draw(frame *fr) {
    for(auto &elem: lines) {
        elem.draw(fr);
    }
}
