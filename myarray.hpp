#ifndef MYARRAY_H
#define MYARRAY_H
#include <stdexcept>
#include <exception>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;
using std::out_of_range;


template<class T, int N> // N ist anzahl der elemente im array, T wird parkplatzsuchender
class myArray {
public:
    myArray() : myArray{ T{} }
    {}

    explicit myArray( T& t ) {
        for (size_t i{}; i < N; ++i) elem[i] = t;
    }

    myArray( const myArray& r ) {
        *this = r;
    }

    myArray( initializer_list<T> in ) {
        std::copy(in.begin(), in.end(), elem);
    }

    myArray& operator=( const myArray<T, N>& r ) {
        for (size_t i{}; i < N; ++i) elem[i] = r.elem[i];
        return *this;
    }

    T& operator[]( int n ) {
        return elem[n];
    } //zugriff

    const T& operator[]( int n ) const {
        return elem[n];
    } // zugriff + const

    T* dataPtr( int n ) {
        return &(elem[n]);
    } //zeiger auf element

    const T* dataPtr( int n ) const {
        return &(elem[n]);
    } //zeiger auf ein element

    int size() const {
        return N;
    }

    void printAll(const T& t) const{
        for (int i=0; i< t.size() ; i++) {
            cout << t[i] << endl;
        };
    }

    void fill( myArray<T,N>& a, const T& val) {
        for (int i = 0; i < N; ++i) {a[i] = val;}
    }

    void fill_at(T obj, int n) {
        if (n < 0 || N <= n) throw out_of_range {"bad index"};
        elem[n] = obj;
    }


    T& at(int n) {
        if (n < 0 || N <= n) throw out_of_range {"bad index"};
        return (elem[n]);
    }


private:

    T elem[N]; //verwahre elemente in member array

};

#endif // MYARRAY_H
