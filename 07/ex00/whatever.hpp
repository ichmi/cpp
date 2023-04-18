#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T const &a, T const &b) {
    return a < b ? a : b;
}

template <typename T>
T max(T const &a, T const &b) {
    return a > b ? a : b;
}

#endif
