#ifndef ITER_HPP
#define ITER_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>

template <typename T>
void iter(T *tab, size_t const &len, void (*fn)(T&)) {
	if (!tab) {
		return ;
    }

	for (size_t i = 0; i < len; ++i) {
		fn(tab[i]);
    }
}

template <typename T>
void iter(T const *tab, size_t const &len, void (*fn)(T const&)) {
	if (!tab) {
		return ;
    }

	for (size_t i = 0; i < len; ++i) {
		fn(tab[i]);
    }
}

template <typename T>
void print(T &data) {
	std::cout << GREEN << data << RES << std::endl;
}

#endif
