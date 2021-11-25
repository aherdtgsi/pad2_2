//
// Created by Andi on 25.11.2021.
//

#ifndef PAD2_2_MYVECTOR_HPP
#define PAD2_2_MYVECTOR_HPP

#include <stdexcept>


template<class T, int N>
class myVector {
public:
    explicit myVector(int size = 0) {
        this->size = size;
        this->capacity = size;
        this->data = new T[size];
    }

    myVector(const myVector& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new T[capacity];
        for (int i = 0; i < size; i++) {
            this->data[i] = other.data[i];
        }
    }

    myVector& operator=(const myVector& other) {
        if (this != &other) {
            delete[] this->data;
            this->size = other.size;
            this->capacity = other.capacity;
            this->data = new T[capacity];
            for (int i = 0; i < size; i++) {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~myVector() {
        delete[] this->data;
    }

    int get_size() const {
        return this->size;
    }

    int get_capacity() const {
        return this->capacity;
    }

    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    T& at(int index) {
        if (index >= 0 && index < size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    const T& operator[](int index) const {
        if (index >= 0 && index < size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    const T& at(int index) const {
        if (index >= 0 && index < size) {
            return this->data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void reserve(int newCapacity) {
        if (newCapacity > capacity) {
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] this->data;
            this->data = newData;
            this->capacity = newCapacity;
        }
    }

    void resize(int newSize, T value) {
        if (newSize > size) {
            T* newData = new T[newSize];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] this->data;
            this->data = newData;
            this->size = newSize;
            this->capacity = newSize;
        } else if (newSize < size) {
            delete[] this->data;
            this->data = new T[newSize];
            this->size = newSize;
            this->capacity = newSize;
        }
        for (int i = 0; i < newSize; i++) {
            this->data[i] = value;
        }
    }

    void push_back(const T& value) {
        if (size == capacity) {
            reserve(capacity * 2);
        }
        this->data[size] = value;
        size++;
    }

private:
    int size{};
    int capacity{};
    T* data{};
};

#endif