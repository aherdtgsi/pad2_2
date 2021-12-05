//
// Created by Andi on 03.12.2021.
//

#ifndef PAD2_2_TESTS_H
#define PAD2_2_TESTS_H
#include "frame.h"
#include "line.h"
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
    ln.draw(&test);
    ln.set_line(53,30,1,1);
    ln.draw(&test);
    ln.set_line(54,30,1,1);
    ln.draw(&test);
    //out of range
    //ln.set_line(577,30,1,1);
    //ln.draw(&test);

}



#endif //PAD2_2_TESTS_H
