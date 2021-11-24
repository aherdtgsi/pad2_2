//
// Created by Andi on 24.11.2021.
//

#include "parkplatz.h"

parkplatz::parkplatz(unsigned int id) {
    if(id>6&&id<10){
        this->setIstDauerparkplatz(true);
    }
    else
        this->setIstDauerparkplatz(false);
    this->setIstBelegt(false);
    this->setId(id);
    this->setName("");
}

bool parkplatz::isIstBelegt() const {
    return ist_belegt;
}

void parkplatz::setIstBelegt(bool istBelegt) {
    ist_belegt = istBelegt;
}

bool parkplatz::isIstDauerparkplatz() const {
    return ist_dauerparkplatz;
}

void parkplatz::setIstDauerparkplatz(bool istDauerparkplatz) {
    ist_dauerparkplatz = istDauerparkplatz;
}

unsigned int parkplatz::getId() const {
    return id;
}

void parkplatz::setId(unsigned int id) {
    parkplatz::id = id;
}

const string &parkplatz::getName() const {
    return name;
}

void parkplatz::setName(const string &name) {
    parkplatz::name = name;
}

void parkplatz::belegen() {
    this->setIstBelegt(true);
}

void parkplatz::freigeben() {
    this->setIstBelegt(false);
}

void parkplatz::dauerparkplatz_belegen(string name) {
    this->setIstBelegt(true);
    this->setName(name);
}

void parkplatz::dauerparkplatz_freigeben() {
    this->setIstBelegt(false);
    this->setName("");
}
