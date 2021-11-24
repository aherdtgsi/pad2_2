//
// Created by Andi on 24.11.2021.
//

//for(auto & elem : inv){
#include "parkhaus.h"

//WER DAS LIEST IST DOOF

void parkhaus::print() {

}

bool parkhaus::belegen() {

    return false;
}

bool parkhaus::dauerparkplatz_belegen() {
    return false;
}

parkhaus::parkhaus(){
    for(unsigned int c=0;c<10;c++){

        parkplatz b(c);
        a.fill_at(b, c);
        delete b;
    }


}
