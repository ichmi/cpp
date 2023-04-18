#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
    std::cout << YELLOW "Array" RES " default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &obj) : _array(NULL), _size(0) {
    std::cout << YELLOW "Array" RES " copy constructor called" << std::endl;

    *this = obj;
}

template <typename T>
Array<T>::~Array(void) {
    std::cout << YELLOW "Array" RES " destructor called" << std::endl;

    delete[] this->_array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs) {
    std::cout << YELLOW "Array" RES " assignment operator called" << std::endl;

    if (this->_array) {
        delete[] this->_array;
    }
    this->_size = rhs._size;
    this->_array = new T[rhs._size];

    for (unsigned int i = 0; i < this->_size; ++i) {
        this->_array[i] = rhs._array[i];
    }

    return *this;
}

template <typename T>
Array<T>::Array(unsigned int size) : _array(NULL), _size(0) {
    std::cout << YELLOW "Array" RES " parametric constructor called" << std::endl;

    if (size > 0) {
        this->_size = size;
        this->_array = new T[size];

        for (unsigned int i = 0; i < size; ++i) {
            this->_array[i] = 0;
        }
    }
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= this->_size) {
		throw std::out_of_range("index out of range");
    }

	return this->_array[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const {
	if (i >= this->_size) {
		throw std::out_of_range("index out of range");
    }

	return this->_array[i];
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return this->_size;
}

template <typename T>
void Array<T>::randomInit(void) {
    std::srand(time(NULL));
    for (unsigned int i = 0; i < this->_size; ++i) {
        this->_array[i] = rand() % 101;
    }
}

template <typename T>
void Array<T>::printArray(void) const {
    std::cout << GRAY "Array = [";
    for (unsigned int i = 0; i < this->_size; ++i) {
        if (i == this->_size - 1) {
            std::cout << GREEN << this->_array[i];
        } else {
            std::cout << GREEN << this->_array[i] << GRAY ", ";
        }
    }
    std::cout << GRAY "]" RES << std::endl;
}

#endif
