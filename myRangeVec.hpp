//
// Created by Andi on 09.12.2021.
//

#ifndef PAD2_2_MYRANGEVEC_HPP
#define PAD2_2_MYRANGEVEC_HPP
#include "myVector.hpp"


template<class T>
class myRangeVec : public myVector<T>
{
public:
    myRangeVec() = delete;
    myRangeVec( int lo, int hi )
            : myVector<T>( hi-lo+1 ), lb{lo} {}
    int low() const { return lb; }
    int high() const { return lb + this->size - 1; }
    const T& operator[]( int i ) const{
        //const version
        return myVector<T>::operator[]( i-lb );
    }
    T& operator[]( int i ) {
        return myVector<T>::operator[]( i-lb );
    }
    T& at( int i ){
        return myVector<T>::operator[]( i-lb );
    }
private:
    int lb; // lower bound, also der untere Index
};


#endif //PAD2_2_MYRANGEVEC_HPP
