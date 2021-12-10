//
// Created by Andi on 03.12.2021.
//

#ifndef PAD2_2_FRAME_H
#define PAD2_2_FRAME_H

#include <array>
#include <iostream>
using std::cout;
using std::endl;


class frame {
    private:
        static const int wide{54}; // globale Konstante: 55 Zeichen pro Zeile
        static const int high{51}; // globale Konstante: 34 Zeilen pro Frame
        std::array<std::array<char,wide>, high > frm;
    public:
        enum color { black = ' ', white = '*' };
        frame();
        void reset(); // Frame leeren, d.h. alle Punkte auf black
        void put_point(int x, int y); // ein Punkt im Frame auf white
        void show() const; // Frame auf die Konsole ausgeben
        static bool on_frame(unsigned int x,unsigned int y) ; // "Clipping"
        static const int getWide();
        static const int getHigh();


};


#endif //PAD2_2_FRAME_H
