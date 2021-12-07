//
// Created by Andi on 03.12.2021.
//

#ifndef PAD2_2_TESTS_H
#define PAD2_2_TESTS_H
#include "frame.h"
#include "line.h"
#include "frame.h"
#include "triangle.h"
using std::cin;


void a1(){
    frame test = frame();
    test.show();
    system("pause");
    test.put_point(1,1);
    test.show();
    system("pause");
    test.put_point(54,1);
    test.show();
    system("pause");
    for(int x=0;x<frame::getHigh();x++){
        test.put_point(x,x);
    }
    test.show();
    system("pause");

    //test.put_point(1,1);
    //test.show();

}


void a1_2(){
    frame test = frame();
    test.show();
    line ln = line();
    //set new line across screen
    ln.set_line(50,1,1,30);
    //draw line in frame
    ln.draw(&test);
    //show frame
    test.show();
}

void a1_3(){
    frame test = frame();
    test.show();
}


void a2_1(){
    frame test = frame();
    point p1 = point(1,1);
    point p2 = point(1,20);
    point p3 = point(50,1);
    triangle t = triangle(p1,p2,p3);
    t.draw(&test);
    test.show();
}

void a2_2(){
    frame test = frame();
    point p1 = point(1,30);
    triangle t = triangle(p1,10,3,3);
    t.draw(&test);
    test.show();
}

#endif //PAD2_2_TESTS_H
