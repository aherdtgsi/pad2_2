//
// Created by Andi on 07.12.2021.
//

#include "triangle.h"
#include "cmath"

triangle::triangle() = default;

triangle::triangle(point p1, point p2, point p3) {
    //generate 3 lines
    line l = line(p1, p2);
    lines.push_back(l);
    l = line(p2, p3);
    lines.push_back(l);
    l = line(p3, p1);
    lines.push_back(l);
}

triangle::triangle(point p1, unsigned int len1,unsigned int len2,unsigned int len3) {
    //sorting
    if(len1<len2)
        std::swap(len1, len2);
    if(len1<len3)
        std::swap(len1, len3);
    if(len2<len3)
        std::swap(len2, len3);

    //wenn len1>=len2+len3 exception
    if(len1>=(len2+len3))
        throw std::invalid_argument("not a correct triangle");

    //calculate p2
    int p2_x = p1.getX()+len1;
    int p2_y = p1.getY();
    point p2 = point(p2_x, p2_y);

    //calculate p3
    int z = int(pow(len1,2) - pow(len2, 2) + pow(len3, 2)) / (2*len1);;
    int h = (int)(sqrt(pow(len3,2)- pow(z,2)));
    int p3_x = p1.getX() + z;
    int p3_y = p1.getY() -h;
    point p3 = point(p3_x,p3_y);

    //generate 3 lines
    line l = line(p1, p2);
    lines.push_back(l);
    l = line(p2, p3);
    lines.push_back(l);
    l = line(p3, p1);
    lines.push_back(l);

}
