//
// Created by Andi on 25.11.2021.
//

#ifndef PAD2_2_TRACER_HPP
#define PAD2_2_TRACER_HPP

#include <iostream>

using std::cout;
using std::endl;

template<class T>
class Tracer {
public:
    Tracer(T val){
        this->value = val;
        cout << "Tracer(T) Constructor" << endl;
        Tracer::setCounter(Tracer::getCounter()+1);
    }


    Tracer(const Tracer& ref){
        cout << "Tracer Copy Constructor" << endl;
        this->value = ref.value;
        //counter++;
        Tracer::setCounter(Tracer::getCounter()+1);
    }

    virtual ~Tracer() {
        cout << "Tracer Destructor" << endl;
        Tracer::setCounter(Tracer::getCounter()-1);
    }

    static int getCounter() {
        return Tracer::counter;
    }

    static void setCounter(int counter) {
        Tracer::counter = counter;
    }

    T getValue() const {
        return value;
    }

    void setValue(T value) {
        Tracer::value = value;
    }
private:
    static int counter;
    T value;
};

template<class T>
int Tracer<T>::counter = 0;
#endif //PAD2_2_TRACER_HPP
