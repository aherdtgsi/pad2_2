#include <iostream>
#include "parkhaus.h"
using std::cout;
using std::cin;
using std::endl;

/*
int main() try{
    parkhaus a;
    a.print();
    char input;
    bool exit;
    string name;
    while (!exit) try {
        cout << "Belegen (A) / Dauerparkplatz belegen (B) / Freigeben nach ID (C) / " << endl <<
                "Dauparkplatz Freigeben nach Name (D) / Dauparkplatz Freigeben nach ID (E)" << endl <<
                "Print(F) Beenden(G)" << endl;
        cin >> input;
        switch (input) {
            case 'A':
                a.belegen();
                break;
            case 'B':
                cout << "Belegen(Name): " << endl;
                cin >> name;
                a.dauerparkplatz_belegen(name);
                break;
            case 'C':
                cout << "Freigeben(ID): " << endl;
                unsigned int id;
                cin >> id;
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
        catch(logic_error &err){
            cout << err.what() << endl;
        }
    return 0;
}
catch(...){
    cout << "unknown error";
}
*/
#include "myVector.hpp"

int main ()try{
    myVector<int> v(0);
    v.print();
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    /*
    v.print();
    v.resize(20,0);
    v.print();
    v.resize(5,0);
    v.print();
    */
    myVector<int> a = v;
    v.print();
    a.print();

}
catch (...){
    cout << "unknown error";
}