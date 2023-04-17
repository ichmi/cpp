#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer {
    private:
        Serializer(void);
        Serializer(Serializer const &obj);
        ~Serializer(void);
        Serializer &operator=(Serializer const &rhs);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
