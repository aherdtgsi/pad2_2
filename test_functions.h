//
// Created by Andi on 26.11.2021.
//

#ifndef PAD2_2_TEST_FUNCTIONS_H
#define PAD2_2_TEST_FUNCTIONS_H

#include <iostream>
#include "parkhaus.h"
using std::cout;
using std::cin;
using std::endl;
using std::invalid_argument;
#include "myVector.hpp"
#include "Tracer.hpp"

void aufgabe1(){
    myVector<int> v(0);
    v.print();
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    v.print();
    v.resize(20, 0);
    v.print();
    v.resize(5, 0);
    v.print();

    myVector<int> y = v;
    v.print();
    y.print();
}

void aufgabe2() {
    parkhaus a;
    a.print();
    char input;
    bool exit;
    string name;
    while (!exit)
        try {
            cout << "Belegen (A) / Dauerparkplatz belegen (B) / Freigeben nach ID (C) / " << endl <<
                 "Dauparkplatz Freigeben nach Name (D) / Dauparkplatz Freigeben nach ID (E)" << endl <<
                 "Print(F) Beenden(G)" << endl;
            cin >> input;
            if (!cin)
                throw std::invalid_argument("wrong input");
            switch (input) {
                case 'A':
                    a.belegen();
                    break;
                case 'B':
                    cout << "Belegen(Name): " << endl;
                    cin >> name;
                    if (!cin)
                        throw std::invalid_argument("wrong input");
                    a.dauerparkplatz_belegen(name);
                    break;
                case 'C':
                    cout << "Freigeben(ID): " << endl;
                    unsigned int id;
                    cin >> id;
                    if (!cin)
                        throw std::invalid_argument("wrong input");
                    a.freigeben(id);
                    break;
                case 'D':
                    cout << "Dauerparkplatz Freigeben(Name)" << endl;
                    cin >> name;
                    a.dauerparkplatz_freigeben(name);
                    break;
                case 'E':
                    cout << "Dauerparkplatz Freigeben(ID)" << endl;
                    unsigned int id2;
                    cin >> id2;
                    a.dauerparkplatz_freigeben(id2);
                    break;
                case 'F':
                    a.print();
                    break;
                case 'G':
                    cout << "Beenden" << endl;
                    exit = true;
                    break;
                default:
                    cout << "Ungueltige Eingabe" << endl;
            }
        }
        catch (logic_error &err) {
            cout << err.what() << endl;


        }
}

void aufgabe3(){

    Tracer<int> z(10);
    cout << z.getCounter() << endl;
    Tracer<int> bs = z;
    cout << z.getCounter() << endl;
    cout << bs.getCounter() << endl;
    Tracer<string> d("asdfasdf");
    //2 Tracer<int> objects
    cout << bs.getCounter() << endl;
    //1 Tracer<String> object
    cout << d.getCounter() << endl;
    cout << d.getValue() << endl;
    if (true) {
        Tracer<string> f = d;
        //2 Tracer<String> objects
        cout << d.getCounter() << endl;
    }
    //1 Tracer<String> object
    cout << d.getCounter() << endl;
    cout << z.getCounter() << endl;


}

#endif //PAD2_2_TEST_FUNCTIONS_H
//test