#ifndef MYARRAY_H
#define MYARRAY_H
#include <stdexcept>
#include <exception>
#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;
using std::out_of_range;


template<class T, int N>
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
        for (int i=0; i< t->size() ; i++) {
            std::cout << t[i] << endl;
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

/*
 * Here's what the above class is doing:
1. The class has a constructor that takes an initializer list.
2. The class has a copy constructor that copies the elements of the source array to itself.
3. The class has an assignment operator that assigns the elements of the source array to itself, and returns *this (the same object).
4. The class has a data pointer member function that returns a pointer to the element at the specified index.
5. The class has a const data pointer member function that returns a const pointer to the element at the specified index.
6. The class has an array subscript operator that returns an object of type T.
7. The class has a const array subscript operator that returns an object of type T.
8. The class has a size member function that returns the number of elements in the array (N).
9. The class has a printAll member function that prints all elements in the array to cout, one per line.
10. The class has a fill member function that fills the array with the specified value.
11. The class has a fill_at member function that sets the element at index n to val, if n is in range (0, N-1).
12. The class has an at member function that returns the element at index n, if n is in range (0, N-1).
13. The class has a private member array of type T.
14. The class has a private size variable of type int.

 */

#endif // MYARRAY_H
