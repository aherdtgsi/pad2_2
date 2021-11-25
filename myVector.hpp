//
// Created by Andi on 25.11.2021.
//

#ifndef PAD2_2_MYVECTOR_HPP
#define PAD2_2_MYVECTOR_HPP

#include <stdexcept>


template<class T>
class myVector {
public:
    myVector(int capacity = 0) {
        cout << "Constuctor myVector()" << endl;
        this->size = 0;
        this->capacity = capacity;
        this->data = new T[capacity];
    }

    myVector(const myVector& other) {
        cout << "CopyConstuctor myVector()" << endl;
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new T[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            this->data[i] = other.data[i];
        }
    }

    myVector& operator=(const myVector& other) {
        if (this != &other) {
            delete[] this->data;
            this->size = other.size;
            this->capacity = other.capacity;
            this->data = new T[this->capacity];
            for (int i = 0; i < this->capacity; i++) {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~myVector() {
        cout << "Destructor myVector()" << endl;
        delete[] this->data;
    }

    int get_size() const {
        return this->size;
    }

    int get_capacity() const {
        return this->capacity;
    }

    T& operator[](int index) {
        if (index >= 0 && index < this->size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    T& at(int index) {
        if (index >= 0 && index < this->size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    const T& operator[](int index) const {
        if (index >= 0 && index < this->size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    const T& at(int index) const {
        if (index >= 0 && index < this->size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void reserve(int newCapacity) {
        if (newCapacity > this->capacity) {
            T* newData = new T[newCapacity];
            for (int i = 0; i < this->size; i++) {
                newData[i] = this->data[i];
            }
            delete[] this->data;
            this->data = newData;
            this->capacity = newCapacity;
        }
    }

    void resize(int newSize, T value) {
        if (newSize > this->size) {
            T *newData = new T[newSize];
            for (int i = 0; i < this->size; i++) {
                newData[i] = this->data[i];
            }
            delete[] this->data;
            this->data = newData;
            this->capacity = newSize;
        }
        else if (newSize < this->size) {
            T* newData = new T[newSize];
            for (int i = 0; i < newSize; i++) {
                newData[i] = this->data[i];
            }
            delete[] this->data;
            this->data = newData;
            this->size = newSize;
            this->capacity = newSize;
        }
    //if equal, nothing happens
    }

    void push_back(const T& value) {
        if (size == capacity) {
            //+1 fixes error with startsize = 0
            reserve((capacity * 2) +1);
        }
        this->data[size] = value;
        size++;
    }

    void print() {
        cout << "Size: " << this->size << " / Capacity: " << this->capacity << endl;
        for (int i = 0; i < this->size; i++) {
            cout << data[i] << endl;
        }
    }

private:
    int size{};
    int capacity{};
    T* data;
};

#endif