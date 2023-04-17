#ifndef BASE_HPP
#define BASE_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RED "\x1b[38;5;196m"
#define RES "\x1b[0m"

#include <iostream>
#include <cstdlib>

class Base {
    public:
        virtual ~Base(void);
};

#endif
