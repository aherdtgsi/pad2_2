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
    unsigned int belegen();
    unsigned int dauerparkplatz_belegen(const string& name);
    bool dauerparkplatz_freigeben(const string& name);
    bool dauerparkplatz_freigeben(unsigned int id);
    bool freigeben(unsigned int id);

private:
    myArray<parkplatz*, 10> a;

};


#endif //PAD2_2_PARKHAUS_H
