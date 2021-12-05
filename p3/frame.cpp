//
// Created by Andi on 03.12.2021.
//

#include "frame.h"
#include <ctime>
#include <chrono>


frame::frame() {
    for (auto &zeile : frm) {
        for (auto &p : zeile) {
            p = black;
        }
    }
}

void frame::reset() {
    for (auto &zeile : frm) {
        for (auto &p : zeile) {
            p = black;
        }
    }
}

void frame::put_point(int x, int y) {
    if(!frame::on_frame(x,y)) {
        throw std::out_of_range("out of range");
    }
    frm[y][x] = white;
}

void frame::show() const {
    //auto start = std::chrono::high_resolution_clock::now();
    for (auto &zeile : frm) {
        for (auto &p : zeile) {
            //Zeiten für 300x200 frame
            //Zeit mit cout: 2-2,3sec
            //cout << p;
            //Zeit mit put: 2-2,3sec
            cout.put(p);
        }
        cout << endl;
    }
    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double, std::milli> result = end - start;
    //cout << "Time (ms): " << result.count() << endl;
}

bool frame::on_frame(unsigned int x,unsigned int y) {
    return (x < wide && y < high);
}

const int frame::getWide() {
    return wide;
}

const int frame::getHigh() {
    return high;
}
