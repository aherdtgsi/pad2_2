//
// Created by Andi on 24.11.2021.
//

#ifndef PAD2_2_PARKHAUS_H
#define PAD2_2_PARKHAUS_H
#include "myarray.hpp"
#include "parkplatz.h"


class parkhaus {
public:
    parkhaus();
    void print();
    bool belegen();
    bool dauerparkplatz_belegen();

private:
    myArray<parkplatz, 10> a;

};


#endif //PAD2_2_PARKHAUS_H
