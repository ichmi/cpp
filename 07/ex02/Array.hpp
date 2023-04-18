#ifndef ARRAY_HPP
#define ARRAY_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RED "\x1b[38;5;196m"
#define RES "\x1b[0m"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array {
    private:
        T           *_array;
        unsigned int _size;

    public:
        Array(void);
        Array(Array const &obj);
        ~Array(void);
        Array &operator=(Array const &rhs);

        Array(unsigned int size);

        T       &operator[](unsigned int i);
        T const &operator[](unsigned int i) const;

        unsigned int size(void) const;
        void         printArray(void) const;
        void         randomInit(void);
};

#include "Array.tpp"

#endif
