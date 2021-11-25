//
// Created by Andi on 24.11.2021.
//

#include "parkhaus.h"


void parkhaus::print() {
    for (int i = 0; i < a.size(); ++i) {
        cout << "Parkplatz Nr. " << i + 1 << ": ";
        if (a[i]->isIstBelegt()) {
            cout << "belegt" << endl;
        } else {
            cout << "frei" << endl;
        }
    }
}


unsigned int parkhaus::belegen() {
    for (int i = 0; i < a.size(); ++i) {
        if (!a[i]->isIstBelegt() && !a[i]->isIstDauerparkplatz()) {
            a[i]->belegen();
            cout << "Parkplatz Nr. " << a[i]->getId() << " wurde belegt" << endl;
            //returning ID, not needed
            return a[i]->getId();
        }
    }
    throw logic_error {"Kein Normaler Parkplatz mehr frei"};
}


unsigned int parkhaus::dauerparkplatz_belegen(const string& name) {
    for (int i = 0; i < a.size(); ++i) {
        if (!a[i]->isIstBelegt() && a[i]->isIstDauerparkplatz()) {
            a[i]->dauerparkplatz_belegen(name);
            cout << "Dauerparkplatz Nr. " << a[i]->getId() << " wurde belegt" << endl;
            //returning ID, not needed
            return a[i]->getId();
        }
    }
    throw logic_error {"Kein Dauerparkplatz mehr frei"};
}

bool parkhaus::freigeben(unsigned int id) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]->getId() == id && a[i]->isIstBelegt()) {
            a[i]->freigeben();
            cout << "Parkplatz Nr. " << a[i]->getId() << "freigegeben" << endl;
            return true;
        }
    }
    throw logic_error {"Parkplatz nicht gefunden oder nicht belegt"};
}


bool parkhaus::dauerparkplatz_freigeben(const string& name) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]->isIstBelegt() && a[i]->isIstDauerparkplatz() && a[i]->getName() == name) {
            a[i]->dauerparkplatz_freigeben();
            cout << "Parkplatz Nr. " << a[i]->getId() << "freigegeben" << endl;
            return true;
        }
    }
    throw logic_error {"Parkplatz nicht gefunden oder nicht belegt"};
}


bool parkhaus::dauerparkplatz_freigeben(unsigned int id) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]->isIstBelegt() && a[i]->isIstDauerparkplatz() && a[i]->getId() == id) {
            a[i]->dauerparkplatz_freigeben();
            cout << "Parkplatz Nr. " << a[i]->getId() << "freigegeben" << endl;
            return true;
        }
    }
    throw logic_error {"Parkplatz nicht gefunden oder nicht belegt"};
}


    parkhaus::parkhaus() {
    for (int i = 0; i < a.size(); ++i) {
        a[i] = new parkplatz(i + 1);
    }
}
