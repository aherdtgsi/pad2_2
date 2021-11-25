//
// Created by Andi on 24.11.2021.
//

#include <stdexcept>
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

void parkplatz::setId(unsigned int id_input) {
    parkplatz::id = id_input;
}

const string &parkplatz::getName() const {
    return name;
}

void parkplatz::setName(const string &name_input) {
    parkplatz::name = name_input;
}

void parkplatz::belegen() {
    if (ist_belegt) {
        throw std::logic_error {"Parkplatz bereits belegt"};
    }
    if (ist_dauerparkplatz) {
        throw std::logic_error {"Parkplatz ist Dauerparkplatz"};
    }
    ist_belegt = true;
}


void parkplatz::freigeben() {
    if (!ist_belegt) {
        throw std::logic_error {"Parkplatz nicht belegt"};
    }
    if (ist_dauerparkplatz) {
        throw std::logic_error {"Parkplatz ist Dauerparkplatz"};
    }
    ist_belegt = false;
}


void parkplatz::dauerparkplatz_belegen(string parkplatz_name) {
    if (ist_belegt) {
        throw std::logic_error {"Parkplatz bereits belegt"};
    }
    if (!ist_dauerparkplatz) {
        throw std::logic_error {"Parkplatz ist kein Dauerparkplatz"};
    }
    ist_belegt = true;
    ist_dauerparkplatz = true;
    this->name = std::move(parkplatz_name);
}


void parkplatz::dauerparkplatz_freigeben() {
    if (!ist_belegt) {
        throw std::logic_error {"Parkplatz nicht belegt"};
    }
    if (!ist_dauerparkplatz) {
        throw std::logic_error {"Parkplatz ist kein Dauerparkplatz"};
    }
    ist_belegt = false;
    ist_dauerparkplatz = false;
    name = "";
}