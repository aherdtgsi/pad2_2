//
// Created by Andi on 03.12.2021.
//

#ifndef PAD2_2_TESTS_H
#define PAD2_2_TESTS_H
#include "frame.h"
#include "line.h"
#include "frame.h"
#include "triangle.h"
#include "../myRangeVec.hpp"
using std::cin;


void a1(){
    frame test = frame();
    test.show();
    system("pause");
    test.put_point(1,1);
    test.show();
    system("pause");
    test.put_point(10,1);
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
    //out of range
    //ln.set_line(100,1,1,30);
    //ln.draw(&test);
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
    triangle t = triangle(p1,20,16,3);
    t.draw(&test);
    test.show();
}


void a3_1(){
    myRangeVec<int> t = myRangeVec<int>(1,5);
    t.push_back(1);
    cout <<t[1] << t.get_size() << t.get_capacity() << t.low();
    //working as intended
    //myRangeVec<int> t2 = myRangeVec<int>(5,0);
    //std::bad_array_new_length
    myRangeVec<int> t3 = myRangeVec<int>(0,0);
    t3.push_back(1);
    t3.push_back(1);
    t3.push_back(1);
    cout << t3[0] <<t3[1];
}

template<class T>
void tf( const myRangeVec<T>& rcmv, myRangeVec<T>& rmv ) {
    //rcmv[1] = 4.2; // Fehler, wie es auch sein soll
    T d1 { rcmv[1] }; // die const-Version []
    //rmv[1] = 0.7; // die nicht-const-Version []
    T d2 { rmv[1] }; // die nicht-const-Version []
    cout << d1 << d2 << endl;
}

void a3_2(){
    myRangeVec<int> t1 = myRangeVec<int>(1,5);
    myRangeVec<int> t2 = myRangeVec<int>(1,5);
    t1.push_back(1);
    t2.push_back(2);
    tf(t1,t2);
}

template<class T>
void tf_at( const myRangeVec<T>& rcmv, myRangeVec<T>& rmv ) {
    //rcmv[1] = 4.2; // Fehler, wie es auch sein soll
    //T d1 { rcmv.at(1) }; // die const-Version []
    //rmv[1] = 0.7; // die nicht-const-Version []
    //T d2 { rmv.at(1) }; // die nicht-const-Version []
    //cout << d1 << d2 << endl;
}

void a3_3(){
    myRangeVec<int> t1 = myRangeVec<int>(1,5);
    myRangeVec<int> t2 = myRangeVec<int>(1,5);
    t1.push_back(1);
    t2.push_back(2);
    tf_at(t1,t2);


}


#endif //PAD2_2_TESTS_H
